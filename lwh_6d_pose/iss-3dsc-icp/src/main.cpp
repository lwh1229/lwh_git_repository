#include <iostream>
#include"KeyPointsAnd3DSC.h"
#include"Registration.h"

using namespace std;

int main(int argc, char** argv)
{
	// 加载点云文件
	PointCloud::Ptr source(new PointCloud);    // 源点云，待配准
	pcl::io::loadPCDFile("../../6d_data/lwh_yolo/model/bottle3_real.pcd", *source);
	PointCloud::Ptr target(new PointCloud);    // 目标点云
	pcl::io::loadPCDFile("../../6d_data/lwh_yolo/scene/bottle3_scene.pcd", *target);

    //--------------------特征点提取及描述子的阈值-------------------
    float step = 0.001;             // 体素滤波格网边长
    float SalientRadius = 0.005;    // ISS 搜索半径
    float NonMaxRadius = 0.01;      // ISS 非极大值抑制半径
    float delta21 = 0.65;           // ISS L2/L1的阈值
    float delta32 = 0.5;            // ISS l3/L2的阈值
    float MinimalRadius = 0.02;     // 3DSC 球面最小半径
    float RadiusSearch = 0.03;      // 3DSC 邻域点半径
    float PointDensityRadius = 0.02;// 3DSC 密度计算阈值
    KeyPointsAnd3DSC IPR(step, SalientRadius, NonMaxRadius, delta21, delta32, MinimalRadius, RadiusSearch, PointDensityRadius);
    //---------------------------提取特征点------------------------
    PointCloud::Ptr source_key(new PointCloud);
    IPR.voxelGridAndKeyPoints(source, source_key);
    cout << "源点云提取特征点个数为：" << source_key->points.size() << endl;
    pcl::io::savePCDFileASCII("Z1Akeypoint.pcd", *source_key);
    PointCloud::Ptr target_key(new PointCloud);
    IPR.voxelGridAndKeyPoints(target, target_key);
    cout << "目标点云提取特征点个数为：" << target_key->points.size() << endl;

    //-----------------------------计算3dsc-----------------------
    pcl::PointCloud<pcl::ShapeContext1980>::Ptr sps_src(new pcl::PointCloud<pcl::ShapeContext1980>());
    pcl::PointCloud<pcl::ShapeContext1980>::Ptr sps_tgt(new pcl::PointCloud<pcl::ShapeContext1980>());
    IPR.computeKeyPoints3DSC(source, source_key, sps_src);
    IPR.computeKeyPoints3DSC(target, target_key, sps_tgt);
    //----------------------------点云配准阈值----------------------
    int RansacIterations = 50000;
    float RansacDistance = 0.0125;
    float Fraction = 0.25;
    float MaxDistance = 0.04;
    int MaxIterations = 35;
    //-----------------------------执行配准-------------------------
    Registration PCR(RansacIterations, RansacDistance, Fraction, MaxDistance, MaxIterations);
    Eigen::Matrix4f FinalTrans;

    FinalTrans = PCR.RegistrationTransform(source_key, sps_src, target_key, sps_tgt);

    PointCloud::Ptr icp(new PointCloud);
    pcl::transformPointCloud(*source, *icp, FinalTrans);
    //--------------------------可视化配准结果----------------------
    PCR.VisualizeRegistration(source, target, icp);
   
    return 0;
}

