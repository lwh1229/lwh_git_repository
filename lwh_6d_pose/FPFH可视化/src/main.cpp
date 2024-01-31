#include<iostream>
#include<vector>
#include <pcl/point_types.h>
#include <pcl/features/fpfh.h>
#include <pcl/io/pcd_io.h>
#include <pcl/features/normal_3d_omp.h>//使用OMP需要添加的头文件
#include <pcl/visualization/histogram_visualizer.h> //直方图的可视化
#include <pcl/visualization/pcl_plotter.h>// 直方图的可视化 方法2

using namespace std;

int main()
{
	//---------------------读取点云----------------------
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	pcl::PCDReader reader;
	reader.read("../../6d_data/Stanford/bunny/bunny.pcd", *cloud);
	//---------------------计算法向量-------------------
	pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> n;//OMP加速
	n.setInputCloud(cloud);
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());
	n.setSearchMethod(tree);//设置近邻搜索算法
	n.setNumberOfThreads(4);//设置openMP的线程数
	// 输出点云 带有法线描述
	n.setKSearch(30);
	pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
	// 计算表面法线特征
	n.compute(*normals);
	//-------------------计算FPFH---------------------
	pcl::FPFHEstimation<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh;
	fpfh.setInputCloud(cloud);
	//fpfh.setSearchSurface(cloud);
	fpfh.setInputNormals(normals);
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree2(new pcl::search::KdTree<pcl::PointXYZ>());
	fpfh.setSearchMethod(tree2);//设置近邻搜索算法
	//输出数据集
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfh_fe(new pcl::PointCloud<pcl::FPFHSignature33>());//fphf特征
	//使用半径在5厘米范围内的所有邻元素。
	//注意：此处使用的半径必须要大于估计表面法线时使用的半径!!!
	fpfh.setRadiusSearch(0.5);
	//计算pfh特征值
	fpfh.compute(*fpfh_fe);
	cout << "phf feature size : " << fpfh_fe->points.size() << endl;
	// 应该与input cloud->points.size ()有相同的大小，即每个点都有一个pfh特征向量

	// ---------------直方图可视化-----------------

	//定义绘图器
	pcl::visualization::PCLPlotter* plotter = new pcl::visualization::PCLPlotter("My Plotter");
	//设置特性
	plotter->setTitle("FPFH");
	plotter->setShowLegend(true);
	cout << pcl::getFieldsList<pcl::FPFHSignature33>(*fpfh_fe);
	plotter->addFeatureHistogram<pcl::FPFHSignature33>(*fpfh_fe, "fpfh", 5, "one_fpfh");/*第2个参数为点云类型的field name，5表示可视化第五个点的FPFH特征
	该参数可通过getFieldsList()返回，并且只限定于注册过的点云类型*/
	plotter->setWindowSize(800, 600);
	plotter->spinOnce(30000000);
	plotter->clearPlots();
	//方法2
	// pcl::visualization::PCLPlotter plotter;
	//plotter.addFeatureHistogram(*fpfh_fe_ptr, 300); //设置的根坐标长度，该值越大，则显示的越细致
	//plotter.plot();

	return 0;
}


