#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/filters/voxel_grid.h>    // 体素下采样滤波
#include <pcl/features/normal_3d_omp.h>// 使用OMP需要添加的头文件
#include <pcl/features/fpfh_omp.h>     // fpfh加速计算的omp(多核并行计算)
#include <pcl/registration/ia_ransac.h>// sac_ia算法
#include <pcl/registration/ndt.h>      // NDT配准算法
#include <boost/thread/thread.hpp>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;

typedef pcl::PointCloud<pcl::PointXYZ> pointcloud;
typedef pcl::PointCloud<pcl::Normal> pointnormal;
typedef pcl::PointCloud<pcl::FPFHSignature33> fpfhFeature;

#pragma region// 下采样滤波
pointcloud::Ptr voxel_grid_fiter(pointcloud::Ptr & inCloud)
{
    pcl::VoxelGrid<pcl::PointXYZ> vs;
    vs.setLeafSize(0.005, 0.005, 0.005);
    vs.setInputCloud(inCloud);
    pointcloud::Ptr outCloud(new pointcloud);
    vs.filter(*outCloud);
   
    return outCloud;
}
// 计算FPFH特征
fpfhFeature::Ptr compute_fpfh_feature(pointcloud::Ptr inCloud)
{
    // 法向量估计
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree;
    pointnormal::Ptr normals(new pointnormal);
    pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> n;
    n.setInputCloud(inCloud);
    n.setNumberOfThreads(8);//设置openMP的线程数
    n.setSearchMethod(tree);
    n.setKSearch(10);
    n.compute(*normals);
    //------------------FPFH估计-------------------------
    fpfhFeature::Ptr fpfh(new fpfhFeature);
    pcl::FPFHEstimationOMP<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> f;
    f.setNumberOfThreads(8); //指定8核计算
    f.setInputCloud(inCloud);
    f.setInputNormals(normals);
    f.setSearchMethod(tree);
    f.setKSearch(10);
    f.compute(*fpfh);

    return fpfh;

}

// 可视化
void  visualize_registration(pcl::PointCloud<pcl::PointXYZ>::Ptr& source, pcl::PointCloud<pcl::PointXYZ>::Ptr& target, pcl::PointCloud<pcl::PointXYZ>::Ptr& regist)
{
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("Registration"));
    int v1 = 0;
    int v2 = 1;
    viewer->setWindowName("SAC-IA+NDT配准结果");
    viewer->createViewPort(0, 0, 0.5, 1, v1);
    viewer->createViewPort(0.5, 0, 1, 1, v2);
    viewer->setBackgroundColor(0, 0, 0, v1);
    viewer->setBackgroundColor(0.05, 0, 0, v2);
    viewer->addText("Raw point clouds", 10, 10, "v1_text", v1);
    viewer->addText("Registed point clouds", 10, 10, "v2_text", v2);
    //原始点云绿色
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> src_h(source, 0, 255, 0);
    //目标点云蓝色
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> tgt_h(target, 0, 0, 255);
    //转换后的源点云红色
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> transe(regist, 255, 0, 0);
    //viewer->setBackgroundColor(255, 255, 255);
    viewer->addPointCloud(source, src_h, "source cloud", v1);
    viewer->addPointCloud(target, tgt_h, "target cloud", v1);

    viewer->addPointCloud(target, tgt_h, "target cloud1", v2);
    viewer->addPointCloud(regist, transe, "pcs cloud", v2);

    //添加坐标系
    //viewer->addCoordinateSystem(0.1);
    //viewer->initCameraParameters();
    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
        boost::this_thread::sleep(boost::posix_time::microseconds(10000));
    }

}
#pragma endregion
int main(int argc, char** argv)
{ 
    // 加载点云数据
    pointcloud::Ptr source_cloud(new pointcloud);
    pointcloud::Ptr target_cloud(new pointcloud);
    pcl::io::loadPCDFile<pcl::PointXYZ>("../../6d_data/lwh_yolo/model/bottle3_real.pcd", *source_cloud);
    pcl::io::loadPCDFile<pcl::PointXYZ>("../../6d_data/lwh_yolo/scene/bottle3_scene.pcd", *target_cloud);
    if (source_cloud->empty() || target_cloud->empty()) 
    {
        cout << "请确认点云文件名称是否正确" << endl;
        return -1;
    }

    pointcloud::Ptr source(new pointcloud);
    pointcloud::Ptr target(new pointcloud);
    source = voxel_grid_fiter(source_cloud);
    target = voxel_grid_fiter(target_cloud);

    // 1、计算源点云和目标点云的FPFH
    fpfhFeature::Ptr source_fpfh = compute_fpfh_feature(source);
    fpfhFeature::Ptr target_fpfh = compute_fpfh_feature(target);
   
    // 2、采样一致性SAC_IA初始配准
    clock_t start, end;
    start = clock();
    pcl::SampleConsensusInitialAlignment<pcl::PointXYZ, pcl::PointXYZ, pcl::FPFHSignature33> sac_ia;
    sac_ia.setInputSource(source);
    sac_ia.setSourceFeatures(source_fpfh);
    sac_ia.setInputTarget(target);
    sac_ia.setTargetFeatures(target_fpfh);
    sac_ia.setMinSampleDistance(0.01);       // 设置样本之间的最小距离
    sac_ia.setMaxCorrespondenceDistance(0.1);// 设置对应点对之间的最大距离
    sac_ia.setNumberOfSamples(200);          // 设置每次迭代计算中使用的样本数量（可省）,可节省时间
    sac_ia.setCorrespondenceRandomness(6);   // 设置在6个最近特征对应中随机选取一个
    pointcloud::Ptr align(new pointcloud);
    sac_ia.align(*align);
    Eigen::Matrix4f initial_RT = Eigen::Matrix4f::Identity();// 定义初始变换矩阵
    initial_RT = sac_ia.getFinalTransformation();
    cout << "\nSAC_IA has converged, score is " << sac_ia.getFitnessScore() << endl;
    cout << "变换矩阵：\n" << initial_RT << endl;
    // 3、正态分布变换（NDT）
    pcl::NormalDistributionsTransform<pcl::PointXYZ, pcl::PointXYZ> ndt;
    ndt.setInputSource(source);	             // 设置要配准的点云
    ndt.setInputTarget(target);              // 设置点云配准目标
    ndt.setStepSize(4);                      // 为More-Thuente线搜索设置最大步长
    ndt.setResolution(0.01);                 // 设置NDT网格结构的分辨率（VoxelGridCovariance）
    ndt.setMaximumIterations(35);            // 设置匹配迭代的最大次数
    ndt.setTransformationEpsilon(0.01);      // 为终止条件设置最小转换差异
    pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    ndt.align(*output_cloud, initial_RT);    // align()函数有第二个参数，输入的是初始变换的估计参数
    end = clock();
    cout << "NDT has converged:" << ndt.hasConverged()
        << " score: " << ndt.getFitnessScore() << endl;
    cout << "变换矩阵：\n" << ndt.getFinalTransformation() << endl;
    cout << "运行时间: " << float(end - start) / CLOCKS_PER_SEC << "s" << endl;
    // 4、使用变换矩阵对未进行滤波的原始源点云进行变换
    pcl::transformPointCloud(*source_cloud, *output_cloud, ndt.getFinalTransformation());

    // 5、可视化
    visualize_registration(source_cloud, target_cloud, output_cloud);
    
    return 0;
}


