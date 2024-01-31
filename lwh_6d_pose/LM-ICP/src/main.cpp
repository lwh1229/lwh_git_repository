#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp_nl.h> //LM-ICP
#include <pcl/console/time.h>   
#include "lmicp.h"

using namespace std;

int
   main()
{
	pcl::console::TicToc time;
	// -------------------------加载源点云---------------------------
	pcl::PointCloud<pcl::PointXYZ>::Ptr source(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile<pcl::PointXYZ>("../../6d_data/lwh_yolo/model/bottle3_real.pcd", *source);
	// 加载目标点云
	pcl::PointCloud<pcl::PointXYZ>::Ptr target(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile<pcl::PointXYZ>("../../6d_data/lwh_yolo/scene/bottle3_scene.pcd", *target);

	// ----------------------随机采样特征点--------------------------
	pcl::PointCloud<pcl::PointXYZ>::Ptr s_k(new pcl::PointCloud<pcl::PointXYZ>);
	sample_point(source,s_k);
	pcl::PointCloud<pcl::PointXYZ>::Ptr t_k(new pcl::PointCloud<pcl::PointXYZ>);
	sample_point(target, t_k);
	time.tic();
	// ------------------------LM-ICP--------------------------------
	pcl::IterativeClosestPointNonLinear<pcl::PointXYZ, pcl::PointXYZ> lmicp;
	lmicp.setInputSource(s_k);
	lmicp.setInputTarget(t_k);
	lmicp.setTransformationEpsilon(1e-10);    //为终止条件设置最小转换差异
	lmicp.setMaxCorrespondenceDistance(10);   //设置对应点对之间的最大距离（此值对配准结果影响较大）。
	lmicp.setEuclideanFitnessEpsilon(0.0001); //设置收敛条件是均方误差和小于阈值， 停止迭代；
	lmicp.setMaximumIterations(35);           //最大迭代次数；  
	pcl::PointCloud<pcl::PointXYZ>::Ptr icp_cloud(new pcl::PointCloud<pcl::PointXYZ>);
	lmicp.align(*icp_cloud);

	cout << "Applied " << 35 << " LM-ICP iterations in " << time.toc() / 1000 << "s" << endl;
	cout << "变换矩阵：\n" << lmicp.getFinalTransformation() << endl;
	// 对源点云进行变换
	pcl::transformPointCloud(*source, *icp_cloud, lmicp.getFinalTransformation());
	//pcl::io::savePCDFileASCII (".pcd", *icp_cloud);
   
	visualize_registration(source, target, icp_cloud);

	return (0);
}


