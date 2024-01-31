#include"Registration.h"

Eigen::Matrix4f Registration::RegistrationTransform(PointCloud::Ptr& key_src, pcl::PointCloud<pcl::ShapeContext1980>::Ptr sps_src,
	PointCloud::Ptr& key_tgt, pcl::PointCloud<pcl::ShapeContext1980>::Ptr sps_tgt)
{
	clock_t start = clock();
	//RANSAC配准
	pcl::console::print_highlight("开始进行配准\n");
	pcl::SampleConsensusPrerejective<PointT, PointT, pcl::ShapeContext1980> ransac;
	ransac.setInputSource(key_src);
	ransac.setSourceFeatures(sps_src);
	ransac.setInputTarget(key_tgt);
	ransac.setTargetFeatures(sps_tgt);
	ransac.setMaximumIterations(m_RansacIterations); //  采样一致性迭代次数
	ransac.setNumberOfSamples(6);                    //  创建假设所需的样本数
	ransac.setCorrespondenceRandomness(10);          //  使用的临近特征点的数目

	ransac.setMaxCorrespondenceDistance(m_RansacDistance); // 判断是否为内点的距离阈值
	ransac.setInlierFraction(m_Fraction);                  //  接受位姿假设所需的内点比例

	PointCloud::Ptr sac_result(new PointCloud);
	ransac.align(*sac_result);

	Eigen::Matrix4f ransac_trans;
	ransac_trans = ransac.getFinalTransformation();
	clock_t sac_time = clock();

	//icp配准
	PointCloud::Ptr icp_result(new PointCloud);
	pcl::IterativeClosestPoint<PointT, PointT> icp;
	icp.setInputSource(key_src);
	icp.setInputTarget(key_tgt);

	icp.setMaxCorrespondenceDistance(m_MaxDistance);
	icp.setMaximumIterations(m_MaxIterations);        // 最大迭代次数
	icp.setTransformationEpsilon(1e-10); // 两次变化矩阵之间的差值
	icp.setEuclideanFitnessEpsilon(0.01);// 均方误差
	icp.align(*icp_result, ransac_trans);
	clock_t end = clock();
	std::cout << "total time: " << (double)(end - start) / (double)CLOCKS_PER_SEC << " s" << std::endl;
	std::cout << "sac time: " << (double)(sac_time - start) / (double)CLOCKS_PER_SEC << " s" << std::endl;
	std::cout << "icp time: " << (double)(end - sac_time) / (double)CLOCKS_PER_SEC << " s" << std::endl;

	std::cout << "ICP has converged:" << icp.hasConverged() << " score: " << icp.getFitnessScore() << std::endl;
	Eigen::Matrix4f icp_trans;
	
	Eigen::Matrix4f FinalTrans = icp.getFinalTransformation();

	return FinalTrans;
}

void  Registration::VisualizeRegistration(PointCloud::Ptr& source, PointCloud::Ptr& target, PointCloud::Ptr& icp)
{
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("RegistrationCloud"));
	int v1 = 0;
	int v2 = 1;
	viewer->createViewPort(0, 0, 0.5, 1, v1);
	viewer->createViewPort(0.5, 0, 1, 1, v2);
	viewer->setBackgroundColor(0, 0, 0, v1);
	viewer->setBackgroundColor(0.05, 0, 0, v2);

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

