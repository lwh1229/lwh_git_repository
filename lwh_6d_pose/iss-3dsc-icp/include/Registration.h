#pragma once
#include"KeyPointsAnd3DSC.h"
#include <pcl/registration/sample_consensus_prerejective.h> // RANSAC配准
#include <pcl/registration/icp.h>      // icp配准
#include <boost/thread/thread.hpp>
#include <pcl/visualization/pcl_visualizer.h> // 可视化

class Registration
{
    //数据成员
    int m_RansacIterations;  // RANSAC算法的最大迭代次数
    float m_RansacDistance;  // RANSAC算法判断是否为内点的距离阈值
    float m_Fraction;        // RANSAC算法的内点比例
    float m_MaxDistance;     // ICP精配准中对应点间最大距离
    int m_MaxIterations;     // ICP最大迭代次数
public:
    Registration(int RansacIterations = 50000, float RansacDistance = 0.0125, float Fraction = 0.25, float MaxDistance=0.04,int MaxIterations = 35) :
        m_RansacIterations(RansacIterations), m_RansacDistance(RansacDistance), m_Fraction(Fraction), m_MaxDistance(MaxDistance), m_MaxIterations(MaxIterations) {}
    ~Registration() {}

    // 成员函数

    Eigen::Matrix4f RegistrationTransform(PointCloud::Ptr& key_src, pcl::PointCloud<pcl::ShapeContext1980>::Ptr sps_src,
        pcl::PointCloud<PointT>::Ptr& key_tgt, pcl::PointCloud<pcl::ShapeContext1980>::Ptr sps_tgt);

    void VisualizeRegistration(PointCloud::Ptr& source, PointCloud::Ptr& target, PointCloud::Ptr& icp);

};

