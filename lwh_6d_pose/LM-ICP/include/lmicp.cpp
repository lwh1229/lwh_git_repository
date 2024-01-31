#include"lmicp.h"

void  sample_point(pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud, pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_rsf, double count)
{
	pcl::RandomSample<pcl::PointXYZ> rs_src;
	rs_src.setInputCloud(cloud);
	rs_src.setSample(count);
	rs_src.filter(*cloud_rsf);
}


void  visualize_registration(pcl::PointCloud<pcl::PointXYZ>::Ptr& source, pcl::PointCloud<pcl::PointXYZ>::Ptr& target,
	pcl::PointCloud<pcl::PointXYZ>::Ptr& icp)
{
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("RegistrationCloud"));
	int v1 = 0;
	int v2 = 1;
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
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> transe(icp, 255, 0, 0);
	//viewer->setBackgroundColor(255, 255, 255);
	viewer->addPointCloud(source, src_h, "source cloud", v1);
	viewer->addPointCloud(target, tgt_h, "target cloud", v1);

	viewer->addPointCloud(target, tgt_h, "target cloud1", v2);
	viewer->addPointCloud(icp, transe, "pcs cloud", v2);

	//添加坐标系
	//viewer->addCoordinateSystem(0.1);
	//viewer->initCameraParameters();
	while (!viewer->wasStopped())
	{
		viewer->spinOnce(100);
		boost::this_thread::sleep(boost::posix_time::microseconds(10000));
	}

}


