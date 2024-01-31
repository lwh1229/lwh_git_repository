#include <iostream>
#include <pcl/console/parse.h>
#include <pcl/console/print.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/keypoints/harris_3d.h> // Harris3D关键点检测
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>

int
main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	if (pcl::io::loadPCDFile<pcl::PointXYZ>("../../6d_data/UWA_scale/scene/rs1_0_1000.pcd", *cloud) == -1) // load the file
	{
		pcl::console::print_error("Couldn't read file %s!\n");
		return (-1);
	}
	cout << "从输入点云中读取：" << cloud->points.size() << "个点" << endl;

	pcl::StopWatch watch; // 计时器

	//-----------------------------Harris关键点提取----------------------------------
	//注意此处PCL的point类型设置为<pcl::PointXYZI>,即除了x、y、z坐标还必须包含强度信息
	//因为Harris的评估值保存在输出点云的(I)分量中，Harris输出点云中的(I)非传统点云中的
	//强度信息，因此后续在保存和可视化输出点云的时候需要通过点的索引来重新获取。
	//-------------------------------------------------------------------------------
	pcl::HarrisKeypoint3D <pcl::PointXYZ, pcl::PointXYZI> harris;
	pcl::PointCloud<pcl::PointXYZI>::Ptr Harris_keypoints(new pcl::PointCloud<pcl::PointXYZI>);
	
	harris.setInputCloud(cloud);     // 提供指向输入数据集的指针
	harris.setMethod(harris.LOWE);   // 设置要计算响应的方法（可以不设置）
	harris.setRadius(0.02);          // 设置法线估计和非极大值抑制的半径。
	harris.setRadiusSearch(0.01);    // 设置用于关键点检测的最近邻居的球半径
	harris.setNonMaxSupression(true);// 是否应该应用非最大值抑制
	harris.setThreshold (0.002);     // 设置角点检测阈值，只有当非极大值抑制设置为true时才有效
	harris.setRefine(true);          // 检测到的关键点是否需要细化，设置为true时，关键点为点云中的点
	harris.setNumberOfThreads(6);    // 初始化调度程序并设置要使用的线程数
	harris.compute(*Harris_keypoints);
	
	cout << "算法运行:" << watch.getTimeSeconds() << "秒" << endl;
	cout << "提取关键点" << Harris_keypoints->points.size() << "个" << endl;
	pcl::PointCloud<pcl::PointXYZ>::Ptr keypoints(new pcl::PointCloud<pcl::PointXYZ>);
	//-----------------------获取关键点的索引-------------------------
	pcl::PointIndicesConstPtr keypoints2_indices = harris.getKeypointsIndices();
	//pcl::PointXYZI格式无法正确保存和显示，这里通过索引从原始点云中获取位于点云中特征点
	pcl::copyPointCloud(*cloud, *keypoints2_indices, *keypoints);  
	pcl::io::savePCDFile("keypointsrgb.pcd", *keypoints, true);
	//----------------------------可视化-----------------------------
	boost::shared_ptr<pcl::visualization::PCLVisualizer>viewer(new pcl::visualization::PCLVisualizer("显示点云"));
	viewer->setBackgroundColor(255, 255, 255);  //设置背景颜色为白色
	viewer->setWindowName("Harris3D关键点检测");
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> harris_color_handler(keypoints, 255, 0, 0);
	viewer->addPointCloud<pcl::PointXYZ>(keypoints, harris_color_handler, "Harris_keypoints");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "Harris_keypoints");
	viewer->addPointCloud(cloud, "input_cloud");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0, 1, 0, "input_cloud");
	while (!viewer->wasStopped())
	{
		viewer->spinOnce(100);
		boost::this_thread::sleep(boost::posix_time::microseconds(1000));
	}

	return (0);
}


