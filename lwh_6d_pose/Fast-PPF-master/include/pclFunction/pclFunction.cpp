#pragma once
#include "pclFunction.h"

using namespace std;
using namespace pcl;

/*该函数的作用是初始化一个可视化窗口，用于显示三维图形。具体来说，该函数的实现包括以下几个步骤：

设置可视化窗口的背景颜色为黑色，使用的函数是viewer->setBackgroundColor(0, 0, 0)。

在可视化窗口中添加一个坐标系，用于方便地观察三维图形的位置和方向，使用的函数是viewer->addCoordinateSystem(0.05)。

初始化可视化窗口的相机参数，使得观察者可以从合适的角度观察三维图形，使用的函数是viewer->initCameraParameters()。

总之，这段代码的作用是初始化一个可视化窗口，为后续的三维图形显示做好准备*/

void CustomVisualizer::init() {
	viewer->setBackgroundColor(0, 0, 0);
	viewer->addCoordinateSystem(0.05);
	viewer->initCameraParameters();
}

/**
* @brief The PassThrough filter is used to identify and/or eliminate points
within a specific range of X, Y and Z values.
* @param cloud_in - input cloud
* @param cloud_out - cloud after the application of the filter - cloud after the application of the filter
* @return void
*/
/*这段代码定义了一个名为passthrough的函数，用于对输入的点云数据进行滤波处理，输出滤波后的点云数据。

该函数的输入参数包括一个指向pcl::PointCloudpcl::PointXYZ类型的常量指针cloud_in，
表示输入的点云数据；一个包含6个float类型元素的向量limits，表示滤波的范围，
其中limits[0]和limits[1]表示z轴方向的滤波范围，limits[2]和limits[3]表示x轴方向的滤波范围，
limits[4]和limits[5]表示y轴方向的滤波范围；一个指向pcl::PointCloudpcl::PointXYZ类型的指针cloud_out，表示输出的滤波后的点云数据。

该函数的实现过程如下：
定义一个pcl::PassThrough<PointXYZ>类型的对象pt，用于进行滤波处理。
定义一个pcl::PointCloudpcl::PointXYZ::Ptr类型的指针cloud_ptz_ptr，表示z轴方向滤波后的点云数据。
将输入点云数据cloud_in作为pt的输入，设置滤波的维度为z轴，设置滤波范围为limits[0]到limits[1]，然后将滤波后的点云数据存储在cloud_ptz_ptr中。
定义一个pcl::PointCloudpcl::PointXYZ::Ptr类型的指针cloud_ptx_ptr，表示x轴方向滤波后的点云数据。将上一步得到的滤波后的点云数据cloud_ptz_ptr作为pt的输入，
设置滤波的维度为x轴，设置滤波范围为limits[2]到limits[3]，然后将滤波后的点云数据存储在cloud_ptx_ptr中。
将上一步得到的滤波后的点云数据cloud_ptx_ptr作为pt的输入，设置滤波的维度为y轴，设置滤波范围为limits[4]到limits[5]，然后将滤波后的点云数据存储在输出参数cloud_out中。
总之，该函数的作用是对输入的点云数据进行三维空间的滤波处理，输出滤波后的点云数据。*/
void passthrough(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud_in, vector<float> limits, pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_out)
{
	pcl::PassThrough<PointXYZ> pt;
	
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptz_ptr(new pcl::PointCloud<pcl::PointXYZ>);
	pt.setInputCloud(cloud_in);
	pt.setFilterFieldName("z");
	//pt.setFilterLimits(0.0, 0.85);//0.81
	pt.setFilterLimits(limits[0], limits[1]);//0.81
	pt.filter(*cloud_ptz_ptr);

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptx_ptr(new pcl::PointCloud<pcl::PointXYZ>);
	pt.setInputCloud(cloud_ptz_ptr);
	pt.setFilterFieldName("x");
	//pt.setFilterLimits(-0.3, 0.3);//0.37
	pt.setFilterLimits(limits[2], limits[3]);//0.81
	pt.filter(*cloud_ptx_ptr);

	pt.setInputCloud(cloud_ptx_ptr);
	pt.setFilterFieldName("y");
	//pt.setFilterLimits(-0.25, 0.25);//0.2
	pt.setFilterLimits(limits[4], limits[5]);//0.81
	pt.filter(*cloud_out);
}

/*
* @brief The Statistical Outliner Remove filter is used to remove noisy measurements, e.g. outliers, from a point cloud dataset
  using statistical analysis techniques.
* @param cloud_in - input cloud
* @param cloud_out - cloud after the application of the filter
* @return void
*/
//总之，该函数的作用是对输入的点云数据进行统计滤波处理，通过计算每个点的邻居数量和标准差乘数阈值来判断离群点，并输出滤波后的点云数据
void statisticalOutlinerRemoval(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_in, int numNeighbors, pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_out) {
	// Create the filtering object
	pcl::StatisticalOutlierRemoval<PointXYZ> sor;
	sor.setInputCloud(cloud_in);
	sor.setMeanK(numNeighbors);
	sor.setStddevMulThresh(1.0);
	sor.filter(*cloud_out);
}

/*
* @brief The VoxelGrid filter is used to simplify the cloud, by wrapping the point cloud
  with a three-dimensional grid and reducing the number of points to the center points within each bloc of the grid.
* @param cloud_in - input cloud
* @param cloud_out - cloud after the application of the filter
* @return void
*/
//该函数的作用是对输入的点云数据进行体素网格滤波处理，通过设置体素的尺寸来控制滤波的程度，并输出滤波后的点云数据。
void voxelgrid(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_in, float size_leaf, pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_out)
{
	// cout << "So diem truoc khi loc voxel " << cloud_in->points.size() << endl;
	pcl::VoxelGrid<PointXYZ> vg;
	vg.setInputCloud(cloud_in);
	vg.setLeafSize(size_leaf, size_leaf, size_leaf); // 3mm
	vg.setDownsampleAllData(true);
	vg.filter(*cloud_out);
	//  cout << "So diem sau khi loc voxel " << cloud_out->points.size() << endl;
}

/*
* @brief The VoxelGrid filter is used to simplify the cloud, by wrapping the point cloud
  with a three-dimensional grid and reducing the number of points to the center points within each bloc of the grid.
* @param cloud_in - input cloud
* @param cloud_out - cloud after the application of the filter
* @return void
*/
//这段代码定义了一个名为uniformsampling的函数，用于对输入的点云数据进行均匀采样处理，输出采样后的点云数据
void uniformsampling(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_in, float radius, pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_out)
{
	pcl::UniformSampling<PointXYZ> uniform_sampling;
	uniform_sampling.setInputCloud(cloud_in);
	uniform_sampling.setRadiusSearch(radius);
	uniform_sampling.filter(*cloud_out);
}

/*
* @brief The SACSegmentation and the ExtractIndices filters are used to identify and
remove the table from the point cloud leaving only the objects.
* @param cloud_in - input cloud
* @param cloud_out - cloud after the application of the filter - cloud after the application of the filter
* @return void
*/
//该函数的作用是对输入的点云数据进行SAC分割处理，通过设置距离阈值来控制分割的精度，并输出分割后的点云数据。
void sacsegmentation_extindices(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_in,double dist_threshold, pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_out)
{
	// Identify the table
	pcl::PointIndices::Ptr sacs_inliers(new pcl::PointIndices);
	pcl::ModelCoefficients::Ptr sacs_coefficients(new pcl::ModelCoefficients);
	pcl::SACSegmentation<PointXYZ> sacs;
	sacs.setOptimizeCoefficients(true);
	sacs.setModelType(pcl::SACMODEL_PLANE);
	sacs.setMethodType(pcl::SAC_RANSAC);
	sacs.setMaxIterations(900);//900
	sacs.setDistanceThreshold(dist_threshold);//16mm
	sacs.setInputCloud(cloud_in);
	sacs.segment(*sacs_inliers, *sacs_coefficients);
	// Remove the table
	pcl::ExtractIndices<PointXYZ> ei;
	ei.setInputCloud(cloud_in);
	ei.setIndices(sacs_inliers);
	ei.setNegative(true);
	ei.filter(*cloud_out);
}

/*
* @brief The RadiusOutlierRemoval filter is used to remove isolated point according to
the minimum number of neighbors desired.
* @param cloud_in - input cloud
* @param cloud_out - cloud after the application of the filter - cloud after the application of the filter
* @return void
*/
//该函数的作用是对输入的点云数据进行半径离群点移除处理，通过设置半径和最小邻居点数来控制离群点的移除，并输出移除离群点后的点云数据。
void radiusoutlierremoval(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_in, float radius, uint16_t min_neighbor, pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_out)
{
	// Remove isolated points
	pcl::RadiusOutlierRemoval<PointXYZ> ror;
	ror.setInputCloud(cloud_in);
	ror.setRadiusSearch(radius);    //2cm        
	ror.setMinNeighborsInRadius(min_neighbor);   //150   
	ror.filter(*cloud_out);
}

/*
* @Tinh phap tuyen dam may diem
* @ cloud_in - cloud input PointType
* @ cloud_out - cloud output XYZRGBNormal
*/
//该函数的作用是对输入的点云数据进行法线估计处理，通过设置最近邻点数或半径来控制法线估计的精度，并输出估计后的法线信息。
void normal(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud_in, int k, float r, char mode, PointCloudNormalType::Ptr& normal_out)
{
	pcl::NormalEstimationOMP<PointXYZ, pcl::Normal> ne;
	pcl::search::KdTree<PointXYZ>::Ptr tree(new pcl::search::KdTree<PointXYZ>);
	// Calculate all the normals of the entire surface
	ne.setInputCloud(cloud_in);
	ne.setNumberOfThreads(8);
	ne.setSearchMethod(tree);
	if (mode == 'K')
	{
		ne.setKSearch(k);//50
		ne.compute(*normal_out);
	}
	else if (mode == 'R')
	{
		ne.setRadiusSearch(r);//2cm
		ne.compute(*normal_out);
	}
}
//这两个函数分别用于计算点云数据的分辨率和直径，通过对点云数据进行最近邻搜索和下采样来实现。
double computeCloudResolution(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
{
	double res = 0.0;
	int n_points = 0;
	int nres;
	std::vector<int> indices(2);
	std::vector<float> sqr_distances(2);
	pcl::search::KdTree<PointXYZ> tree;
	tree.setInputCloud(cloud);

	for (std::size_t i = 0; i < cloud->size(); ++i)
	{
		if (!std::isfinite((*cloud)[i].x))
		{
			continue;
		}
		//Considering the second neighbor since the first is the point itself.
		nres = tree.nearestKSearch(i, 2, indices, sqr_distances);
		if (nres == 2)
		{
			res += sqrt(sqr_distances[1]);
			++n_points;
		}
	}
	if (n_points != 0)
	{
		res /= n_points;
	}
	return res;
}

double computeCloudDiameter(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_downsampled(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::VoxelGrid<PointXYZ> vg;
	vg.setInputCloud(cloud);
	vg.setLeafSize(0.005f, 0.005f, 0.005f);
	vg.setDownsampleAllData(false);
	vg.filter(*cloud_downsampled);

	double diameter_sqr = 0;
	for (size_t i = 0; i < cloud_downsampled->points.size(); i += 10)
	{
		for (size_t j = 0; j < cloud_downsampled->points.size(); j += 10)
		{
			if (i == j)
				continue;
			double distance_sqr = (cloud_downsampled->points[i].x - cloud_downsampled->points[j].x)*(cloud_downsampled->points[i].x - cloud_downsampled->points[j].x)
				+ (cloud_downsampled->points[i].y - cloud_downsampled->points[j].y)*(cloud_downsampled->points[i].y - cloud_downsampled->points[j].y)
				+ (cloud_downsampled->points[i].z - cloud_downsampled->points[j].z)*(cloud_downsampled->points[i].z - cloud_downsampled->points[j].z);
			if (distance_sqr > diameter_sqr)
			{
				diameter_sqr = distance_sqr;
			}
		}
	}
	return sqrt(diameter_sqr);
}
