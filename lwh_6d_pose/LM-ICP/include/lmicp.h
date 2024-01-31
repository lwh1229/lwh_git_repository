#pragma once
#include <pcl/filters/random_sample.h>//采取固定数量的点云
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>

void  sample_point(pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud, pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_rsf, double count = 1000);

void  visualize_registration(pcl::PointCloud<pcl::PointXYZ>::Ptr& source, pcl::PointCloud<pcl::PointXYZ>::Ptr& target,
	pcl::PointCloud<pcl::PointXYZ>::Ptr& icp);

