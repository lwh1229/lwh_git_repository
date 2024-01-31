#ifndef ISS3D_SHOT_RANSAC_ICP_H
#define ISS3D_SHOT_RANSAC_ICP_H
 
#include"f_pipeline_setup.h"
#include <string>
// Basics
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/io.h>
#include <pcl/point_cloud.h>
#include <Eigen/Dense>
#include <pcl/console/time.h>
 
// Feature Extraction
#include <pcl/filters/filter.h>
#include <pcl/keypoints/iss_3d.h>
 
 
// Feature Descriptors
#include <pcl/features/normal_3d.h>
#include <pcl/features/shot.h>
#include <pcl/features/shot_lrf.h>
#include <pcl/search/kdtree.h>
 
//downsample
#include <pcl/filters/voxel_grid.h>
 
 
// Registration
#include <pcl/registration/correspondence_estimation.h>
#include <boost/thread/thread.hpp>
#include <pcl/registration/sample_consensus_prerejective.h>
#include <pcl/registration/ia_ransac.h>
#include <pcl/registration/icp.h>
 
// Visualization
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/histogram_visualizer.h>
#include <pcl/visualization/pcl_plotter.h>// 直方图的可视化
 
using pcl::NormalEstimation;
using pcl::search::KdTree;
using namespace datastream;
using namespace iss3dparm;
 
// typedef shortcut
typedef pcl::PointXYZRGB PointT;
typedef pcl::PointCloud<PointT> PointCloud;
typedef pcl::SHOT1344 SHOTSignT;
typedef pcl::PointCloud<SHOTSignT> PointCloudSHOTDesc;
typedef pcl::ReferenceFrame PointRef;
 
void visualize_registration(PointCloud::Ptr pcd_src, PointCloud::Ptr pcd_tar, PointCloud::Ptr pcd_final);
void visualize_keypoints(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcd_src_og, pcl::PointCloud<pcl::PointXYZ>::Ptr pcd_keypoints);
double computeCloudResolution(const pcl::PointCloud<PointT>::ConstPtr& cloud);
/*
class iss3d_Shot_Ransac_Icp
{
public:
    iss3d_Shot_Ransac_Icp();
    // Registration Visualization
    void visualize_registration(PointCloud::Ptr pcd_src, PointCloud::Ptr pcd_tar, PointCloud::Ptr pcd_final);
    void visualize_keypoints(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcd_src_og, pcl::PointCloud<pcl::PointXYZ>::Ptr pcd_keypoints);
    double computeCloudResolution(const pcl::PointCloud<PointT>::ConstPtr& cloud);
 
    int fpip_ISS3D_CSHOT_RANSAC_ICP();
};
*/
#endif // ISS3D_SHOT_RANSAC_ICP_H
