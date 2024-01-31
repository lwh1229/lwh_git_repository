#include <pcl/registration/ia_ransac.h>//采样一致性
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/features/fpfh_omp.h>
#include <pcl/search/kdtree.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/voxel_grid.h>//
#include <pcl/filters/filter.h>//
#include <pcl/registration/icp.h>//icp配准
#include <pcl/visualization/pcl_visualizer.h>//可视化
#include <time.h>//时间
#include <boost/thread.hpp>

 
using pcl::NormalEstimation;
using pcl::search::KdTree;
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloud;
 
 
//点云可视化
void visualize_pcd(PointCloud::Ptr pcd_src, PointCloud::Ptr pcd_tgt, PointCloud::Ptr pcd_final)
{
	// 初始化点云可视化界面
	boost::shared_ptr<pcl::visualization::PCLVisualizer>
		viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));
	//第一个窗口显示input_cloud,第二个窗口显示target_cloud,第三个窗口显示配准之后的结果
	int v1(0), v2(0), v3(0);
	viewer->createViewPort(0, 0, 0.5, 1, v1);//第一个窗口位置、颜色
	//0, 0表示视口的左上角在屏幕上的位置，这里是屏幕的左上角。0.5, 1表示视口的宽度和高度，这里是屏幕宽度的一半和高度的全尺寸。v1表示视口的颜色。
	viewer->setBackgroundColor(0, 0, 0, v1);
	viewer->createViewPort(0.5, 0, 1, 1, v2);//第二个窗口位置以及背景颜色
	viewer->setBackgroundColor(0, 0, 0, v2);
	// viewer_final->createViewPort (0.66,0,1,1,v3);//第三个窗口位置、颜色
	// viewer_final->setBackgroundColor (0, 0, 0,v3);
	 //对待一个窗口显示
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> input_color(pcd_src, 0, 255, 0);//对点云添加颜色
	viewer->addPointCloud<pcl::PointXYZ>(pcd_src, input_color, "input color", v1);//viewer是窗口，添加点云
 
	//对目标点云着色（红色）并可视化
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ>
		target_color(pcd_tgt, 255, 0, 0);//b变红色
	//对第二个视口显示
	viewer->addPointCloud<pcl::PointXYZ>(pcd_tgt, target_color, "target cloud0", v1);
	viewer->addPointCloud<pcl::PointXYZ>(pcd_tgt, target_color, "target cloud", v2);
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
		1, "target cloud");
 
	//对转换后的目标点云着色（绿色）并可视化
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ>
		output_color(pcd_final, 0, 255, 0);
	viewer->addPointCloud<pcl::PointXYZ>(pcd_final, output_color, "output cloud", v2);
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
		1, "output cloud");
 
	// 启动可视化
	viewer->addCoordinateSystem(0.01);
	viewer->initCameraParameters();
	//等待直到可视化窗口关闭。
	while (!viewer->wasStopped())
	{
		viewer->spinOnce(100);
		boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	}
}
 
//由旋转平移矩阵计算旋转角度
void matrix2angle(Eigen::Matrix4f &result_trans, Eigen::Vector3f &result_angle)
{
	double ax, ay, az;
	if (result_trans(2, 0) == 1 || result_trans(2, 0) == -1)
	{
		az = 0;
		double dlta;
		dlta = atan2(result_trans(0, 1), result_trans(0, 2));
		if (result_trans(2, 0) == -1)
		{
			ay = M_PI / 2;
			ax = az + dlta;
		}
		else
		{
			ay = -M_PI / 2;
			ax = -az + dlta;
		}
	}
	else
	{
		ay = -asin(result_trans(2, 0));
		ax = atan2(result_trans(2, 1) / cos(ay), result_trans(2, 2) / cos(ay));
		az = atan2(result_trans(1, 0) / cos(ay), result_trans(0, 0) / cos(ay));
	}
	result_angle << ax, ay, az;
 
	cout << "x轴旋转角度：" << ax << endl;
	cout << "y轴旋转角度：" << ay << endl;
	cout << "z轴旋转角度：" << az << endl;
}
 
 
int main(int argc, char** argv)
{
	//加载点云文件
	PointCloud::Ptr cloud_src_o(new PointCloud);//原点云，待配准
	pcl::io::loadPCDFile("../../6d_data/lwh_yolo/model/bottle3_real.pcd", *cloud_src_o);
	PointCloud::Ptr cloud_tgt_o(new PointCloud);//目标点云
	pcl::io::loadPCDFile("../../6d_data/lwh_yolo/scene/bottle3_scene.pcd", *cloud_tgt_o);
 
	//构造变换矩阵，使目标点云旋转一定的角度成为待配准点云
	/*
	Eigen::AngleAxisf rotation(M_PI/2.85, Eigen::Vector3f::UnitZ());
	Eigen::Translation3f translation(3.79387, 1.720047, 0);
	Eigen::Matrix4f T = (translation * rotation).matrix();
	pcl::transformPointCloud(*cloud_tgt_o, *cloud_src_o, T);
	*/
 
	clock_t start = clock();
 
	//去除NAN点
	std::vector<int> indices_src; //保存去除的点的索引
	pcl::removeNaNFromPointCloud(*cloud_src_o, *cloud_src_o, indices_src);
	std::cout << "remove *cloud_src_o nan" << endl;
	//这段代码的作用是去除点云数据中的NAN点，即无效点。首先定义了一个名为indices_src的整型向量，用于保存被去除的点的索引

	std::vector<int> indices_tgt;
	pcl::removeNaNFromPointCloud(*cloud_tgt_o, *cloud_tgt_o, indices_tgt);
	std::cout << "remove *cloud_tgt_o nan" << endl;
 
	//下采样滤波 原来lefisize0.05
	pcl::VoxelGrid<pcl::PointXYZ> voxel_grid;
	voxel_grid.setLeafSize(0.08, 0.08, 0.08);
	voxel_grid.setInputCloud(cloud_src_o);
	PointCloud::Ptr cloud_src(new PointCloud);
	voxel_grid.filter(*cloud_src);
	std::cout << "down size *cloud_src_o from " << cloud_src_o->size() << "to" << cloud_src->size() << endl;
 
	pcl::VoxelGrid<pcl::PointXYZ> voxel_grid_2;
	voxel_grid_2.setLeafSize(0.08, 0.08, 0.08);
	voxel_grid_2.setInputCloud(cloud_tgt_o);
	PointCloud::Ptr cloud_tgt(new PointCloud);
	voxel_grid_2.filter(*cloud_tgt);
	std::cout << "down size *cloud_tgt_o from " << cloud_tgt_o->size() << "to" << cloud_tgt->size() << endl;
 
 
	//计算表面法线
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne_src;
	ne_src.setInputCloud(cloud_src);
	pcl::search::KdTree< pcl::PointXYZ>::Ptr tree_src(new pcl::search::KdTree< pcl::PointXYZ>());
	ne_src.setSearchMethod(tree_src);
	pcl::PointCloud<pcl::Normal>::Ptr cloud_src_normals(new pcl::PointCloud< pcl::Normal>);
	ne_src.setKSearch(10);
	ne_src.compute(*cloud_src_normals);
 
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne_tgt;
	ne_tgt.setInputCloud(cloud_tgt);
	pcl::search::KdTree< pcl::PointXYZ>::Ptr tree_tgt(new pcl::search::KdTree< pcl::PointXYZ>());
	ne_tgt.setSearchMethod(tree_tgt);
	pcl::PointCloud<pcl::Normal>::Ptr cloud_tgt_normals(new pcl::PointCloud< pcl::Normal>);
	//ne_tgt.setKSearch(20);
	ne_tgt.setKSearch(10);
	ne_tgt.compute(*cloud_tgt_normals);
 
	//计算FPFH
	/*首先创建了一个FPFHEstimationOMP对象fpfh_src，然后通过setNumberOfThreads方法指定了使用4个核心进行计算。
	接着通过setInputCloud和setInputNormals方法分别设置了输入的点云和法线信息。然后创建了一个KdTree搜索对象tree_src_fpfh，
	并将其设置为搜索方法。接着通过setKSearch方法设置了每个点的最近邻数为10。最后调用compute方法计算FPFH特征，
	并将结果存储在fpfhs_src中。最后输出了一条计算完成的信息。*/
	pcl::FPFHEstimationOMP<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_src;
	fpfh_src.setNumberOfThreads(4);//指定4核计算
	fpfh_src.setInputCloud(cloud_src);
	fpfh_src.setInputNormals(cloud_src_normals);
	pcl::search::KdTree<PointT>::Ptr tree_src_fpfh(new pcl::search::KdTree<PointT>);
	fpfh_src.setSearchMethod(tree_src_fpfh);
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfhs_src(new pcl::PointCloud<pcl::FPFHSignature33>());
	fpfh_src.setKSearch(10);
	fpfh_src.compute(*fpfhs_src);
	std::cout << "compute *cloud_src fpfh" << endl;
 
	pcl::FPFHEstimationOMP<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_tgt;
	fpfh_tgt.setNumberOfThreads(4);//指定4核计算
	fpfh_tgt.setInputCloud(cloud_tgt);
	fpfh_tgt.setInputNormals(cloud_tgt_normals);
	pcl::search::KdTree<PointT>::Ptr tree_tgt_fpfh(new pcl::search::KdTree<PointT>);
	fpfh_tgt.setSearchMethod(tree_tgt_fpfh);
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfhs_tgt(new pcl::PointCloud<pcl::FPFHSignature33>());
	fpfh_tgt.setKSearch(10);
	fpfh_tgt.compute(*fpfhs_tgt);
	std::cout << "compute *cloud_tgt fpfh" << endl;
 
	//SAC配准
	pcl::SampleConsensusInitialAlignment<pcl::PointXYZ, pcl::PointXYZ, pcl::FPFHSignature33> scia;
	scia.setInputSource(cloud_src);
	scia.setInputTarget(cloud_tgt);
	scia.setSourceFeatures(fpfhs_src);
	scia.setTargetFeatures(fpfhs_tgt);
	//scia.setMinSampleDistance(1);
	//scia.setNumberOfSamples(2);
	//scia.setCorrespondenceRandomness(20);
	PointCloud::Ptr sac_result(new PointCloud);
	scia.align(*sac_result);
	//PointCloud::Ptr sac_result(new PointCloud);：创建一个指向点云的指针，用于存储配准后的结果。
    //scia.align(*sac_result);：使用SacIA算法对源点云进行配准，并将结果存储在sac_result中
	std::cout << "sac has converged:" << scia.hasConverged() << "  score: " << scia.getFitnessScore() << endl;
	//输出配准是否收敛以及配准的得分
	Eigen::Matrix4f sac_trans;
	sac_trans = scia.getFinalTransformation();
	std::cout << sac_trans << endl;
	//pcl::io::savePCDFileASCII("bunny_transformed_sac.pcd", *sac_result);
	clock_t sac_time = clock();
 
	//icp配准
	PointCloud::Ptr icp_result(new PointCloud);
	pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
	icp.setInputSource(cloud_src);
	icp.setInputTarget(cloud_tgt_o);//icp这里为什么用的全是初始点云，还是cloud_src已经发生变换
	//Set the max correspondence distance to 4cm (e.g., correspondences with higher distances will be ignored)
	icp.setMaxCorrespondenceDistance(1.0);
	// 最大迭代次数
	icp.setMaximumIterations(100000);
	// 两次变化矩阵之间的差值
	icp.setTransformationEpsilon(1e-10);
	// 均方误差
	icp.setEuclideanFitnessEpsilon(0.001);
	icp.align(*icp_result, sac_trans);//这里开始用到粗配准，sac_tarns是上面得到的初始变换矩阵
 
	clock_t end = clock();
	cout << "total time: " << (double)(end - start) / (double)CLOCKS_PER_SEC << " s" << endl;
	cout << "sac time: " << (double)(sac_time - start) / (double)CLOCKS_PER_SEC << " s" << endl;
	cout << "icp time: " << (double)(end - sac_time) / (double)CLOCKS_PER_SEC << " s" << endl;
 
	std::cout << "ICP has converged:" << icp.hasConverged()
		<< " score: " << icp.getFitnessScore() << std::endl;
	Eigen::Matrix4f icp_trans;
	icp_trans = icp.getFinalTransformation();
	//cout<<"ransformationProbability"<<icp.getTransformationProbability()<<endl;
	std::cout << icp_trans << endl;
	//使用创建的变换对未过滤的输入点云进行变换
	pcl::transformPointCloud(*cloud_src_o, *icp_result, icp_trans);
	//保存转换的输入点云
	//pcl::io::savePCDFileASCII("_transformed_sac_ndt.pcd", *icp_result);
 
	//计算误差
	double a_error_x, a_error_y, a_error_z;
	double t_error_x, t_error_y, t_error_z;
	Eigen::Vector3f ANGLE_result;
	matrix2angle(icp_trans, ANGLE_result);
	cout << "计算得到的平移距离" << endl << "x轴平移" << icp_trans(0, 3) << endl << "y轴平移" << icp_trans(1, 3) << endl << "z轴平移" << icp_trans(2, 3) << endl;
 
	//可视化
	visualize_pcd(cloud_src_o, cloud_tgt_o, icp_result);
 
	return (0);
}
