#include "PPF.h"

std::string DescriptorPPF::getType()
{
	return type;
}

void DescriptorPPF::setModelPath(std::string model_path_)
{
	model_filename_ = model_path_;
}

/*这段代码是一个函数，函数名为 DescriptorPPF::loadModel()。
该函数的主要作用是加载模型文件，并从6个视角采样点云数据，最后将所有视角的点云数据合并成一个点云模型。
函数首先初始化了一个自定义的可视化工具customViewer。
然后根据模型文件的扩展名，选择不同的加载方式，如果是.stl格式，则使用meshSampling函数采样点云数据，
否则如果是.pcd格式，则使用pcl::io::loadPCDFile函数加载点云数据。
接着，函数计算了模型的最小和最大点，以及模型的平均点，然后根据这些信息计算出一个正方体的边长，并计算出6个视角的相机位置。
接下来，函数循环遍历6个视角，对每个视角的点云数据进行HPR计算，然后将所有视角的点云数据合并成一个点云模型。
最后，函数对点云模型进行中心化处理，并进行可视化展示。函数返回true表示加载模型成功。*/
bool DescriptorPPF::loadModel() {
	customViewer.init();
	std::cout << "Step 1: Load STL file and perform point sampling from each view" << std::endl;
	std::getchar();
	std::string file_extension = model_filename_.substr(model_filename_.find_last_of('.'));
	if (file_extension == ".stl" || file_extension == ".STL")
	{
		std::cout << "Loading mesh..." << std::endl;
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz(new pcl::PointCloud<pcl::PointXYZ>());
		//0.0005f
		meshSampling(model_filename_, 1000000, 0.005f, false, cloud_xyz);

		pcl::copyPointCloud(*cloud_xyz, *model_sampling);
	}
	else if (file_extension == ".pcd")
	{
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz(new pcl::PointCloud<pcl::PointXYZ>());
		if (pcl::io::loadPCDFile(model_filename_, *cloud_xyz) < 0)
		{
			
			std::cout << "Error loading PCD model cloud." << std::endl;
			return false;
		}
		pcl::copyPointCloud(*cloud_xyz, *model_sampling);
	}

	//---- Calculate point cloud from 6 views and combine ------
	std::vector<std::vector<float>> camera_pos(6);
	pcl::PointXYZ minPt, maxPt, avgPt;

	pcl::getMinMax3D(*model_sampling, minPt, maxPt);
	avgPt.x = (minPt.x + maxPt.x) / 2;
	avgPt.y = (minPt.y + maxPt.y) / 2;
	avgPt.z = (minPt.z + maxPt.z) / 2;

	float cube_length = std::max(maxPt.x - minPt.x, std::max(maxPt.y - minPt.y, maxPt.z - minPt.z));

	minPt.x = avgPt.x - cube_length;
	minPt.y = avgPt.y - cube_length;
	minPt.z = avgPt.z - cube_length;
	maxPt.x = avgPt.x + cube_length;
	maxPt.y = avgPt.y + cube_length;
	maxPt.z = avgPt.z + cube_length;

	camera_pos[0] = { avgPt.x, minPt.y, avgPt.z };
	camera_pos[1] = { maxPt.x, avgPt.y, avgPt.z };
	camera_pos[2] = { avgPt.x, maxPt.y, avgPt.z };
	camera_pos[3] = { minPt.x, avgPt.y, avgPt.z };
	camera_pos[4] = { avgPt.x, avgPt.y, maxPt.z };
	camera_pos[5] = { avgPt.x, avgPt.y, minPt.z };


	for (int i = 0; i < static_cast<int>(camera_pos.size()); ++i)
	{
		std::cout << "Preparing Viewpoint " << i << ".....";
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz_HPR(new pcl::PointCloud<pcl::PointXYZ>());
		HPR(model_sampling, camera_pos[i], 3, cloud_xyz_HPR); //calculate from i view with HPR

		customViewer.viewer->removeAllShapes();
		customViewer.viewer->removeAllPointClouds();
		customViewer.viewer->addPointCloud(cloud_xyz_HPR);
		std::getchar();

		*model += *cloud_xyz_HPR;//combine

	}

	std::cout << "Assemble all viewpoints...";
	customViewer.viewer->removeAllShapes();
	customViewer.viewer->removeAllPointClouds();
	customViewer.viewer->addPointCloud(model);
	std::getchar();

	// ------- centering the model ----------------
	Eigen::Vector3d sum_of_pos = Eigen::Vector3d::Zero();
	for (const auto& p : *(model)) sum_of_pos += p.getVector3fMap().cast<double>();

	Eigen::Matrix4d transform_centering = Eigen::Matrix4d::Identity();
	transform_centering.topRightCorner<3, 1>() = -sum_of_pos / model->size();

	pcl::transformPointCloud(*model, *model, transform_centering);
	pcl::transformPointCloud(*model, *model, Eigen::Vector3f(0, 0, 0), Eigen::Quaternionf(0.7071, 0, -0.7071, 0));

	std::cout << "Centering Model...\n";
	customViewer.viewer->removeAllShapes();
	customViewer.viewer->removeAllPointClouds();
	customViewer.viewer->addPointCloud(model);
	std::getchar();

	

	return true;
}

/*
数的主要步骤如下：

打印输出"Preparing Model Descriptor Offline....."。
载入模型点云数据，如果载入失败则返回false。
打印输出"Step 2: Prepare Point Pair Feature descriptors of model"。
计算模型的直径，即模型中任意两个点之间的最远距离，并打印输出直径值。
根据直径值设置一些参数，用于生成通用的描述符。
使用体素网格滤波器对模型进行滤波，将滤波后的结果保存在model_keypoints中。
计算整个模型表面的法线。
将模型的关键点和法线合并为一个新的点云数据model_keypoints_with_normals。
计算模型的PPF描述符，将结果保存在descriptors_PPF中。
将descriptors_PPF设置为PPF哈希搜索的输入特征云。
打印输出"Done with Preparing Model Descriptor Offline....."。
等待用户按下回车键。
返回true表示模型描述符准备完成。*/
bool DescriptorPPF::prepareModelDescriptor()
{
	std::cout << "Preparing Model Descriptor Offline.....\n" << std::endl;
	//  Load model cloud
	if (!loadModel())
		return false;

	std::cout << "Step 2: Prepare Point Pair Feature descriptors of model\n";
	//Model diameter is the furthest distance from any 2 points of the cloud
	double diameter_model = computeCloudDiameter(model);
	std::cout << "Diameter : " << diameter_model << std::endl;
	//We set the params based on the diameter to have general purpose
	samp_rad = t_sampling * diameter_model;
	norm_rad = 2 * samp_rad;
	Lvoxel = samp_rad;


	//Voxel grid filter
	pcl::VoxelGrid<pcl::PointXYZ> vg;
	vg.setInputCloud(model);
	vg.setLeafSize(samp_rad, samp_rad, samp_rad);
	vg.setDownsampleAllData(false);
	vg.filter(*model_keypoints);

	// Calculate all the normals of the entire surface
	pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
	pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
	ne.setInputCloud(model_keypoints);
	ne.setSearchSurface(model);
	ne.setNumberOfThreads(8);
	ne.setSearchMethod(tree);
	ne.setRadiusSearch(norm_rad);
	ne.compute(*normals);

	pcl::concatenateFields(*model_keypoints, *normals, *model_keypoints_with_normals);

	//Calculate PPF Descriptor of the model
	pcl::PointCloud<pcl::PPFSignature>::Ptr descriptors_PPF = pcl::PointCloud<pcl::PPFSignature>::Ptr(new pcl::PointCloud<pcl::PPFSignature>());
	pcl::PPFEstimation<pcl::PointNormal, pcl::PointNormal, pcl::PPFSignature> ppf_estimator;
	ppf_estimator.setInputCloud(model_keypoints_with_normals);
	ppf_estimator.setInputNormals(model_keypoints_with_normals);
	ppf_estimator.compute(*descriptors_PPF);

	ppf_hashmap_search->setInputFeatureCloud(descriptors_PPF);

	std::cout << "Done with Preparing Model Descriptor Offline....." << std::endl;
	std::getchar();
	return true;
}
/*这段代码的功能是将传入的点云数据存储到latestCloud变量中，并输出最新点云数据的大小。*/
void DescriptorPPF::storeLatestCloud(const PointCloudType::ConstPtr &cloud)
{
	latestCloud = cloud->makeShared();
	std::cout << "Cloud Update with Size " << latestCloud->points.size() << " ........." << std::endl;

}

/*这段代码是一个点云处理的流程，主要包括以下几个步骤：

首先判断latestCloud是否为空，如果为空则直接返回。
创建一系列点云对象，包括colored_scene、captured_scene、passthroughed_scene、voxelgrid_filtered_scene、segmented_scene、statistical_filtered_scene、scene、scene_keypoints和scene_keypoints_with_normals。
将latestCloud的数据复制到captured_scene和colored_scene中，并使用颜色处理器将colored_scene转换为RGB格式。
在可视化窗口中显示colored_scene，并等待用户按下任意键继续。
进行预处理，首先进行RANSAC分割并移除最大的平面（桌面），将结果保存到segmented_scene中。
将segmented_scene的数据复制到scene中，并判断scene是否为空，如果为空则跳过当前帧的处理。
在可视化窗口中显示scene，并等待用户按下任意键继续。
使用Voxel Grid对scene进行下采样，并进行统计滤波去除噪点，将结果保存到scene_keypoints中。
在可视化窗口中显示scene_keypoints，并等待用户按下任意键继续。
计算scene_keypoints的法线，并将结果保存到scene_keypoints_with_normals中。
在可视化窗口中显示scene_keypoints_with_normals，并等待用户按下任意键继续。*/
void DescriptorPPF::_3D_Matching()
{
	if (latestCloud->size() == 0)
	{
		return;
	}
	auto start = std::chrono::high_resolution_clock::now(); 
	//Scene
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr colored_scene = pcl::PointCloud<pcl::PointXYZRGB>::Ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	pcl::PointCloud<pcl::PointXYZ>::Ptr captured_scene = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::PointCloud<pcl::PointXYZ>::Ptr passthroughed_scene = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::PointCloud<pcl::PointXYZ>::Ptr voxelgrid_filtered_scene = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::PointCloud<pcl::PointXYZ>::Ptr segmented_scene = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::PointCloud<pcl::PointXYZ>::Ptr statistical_filtered_scene = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::PointCloud<pcl::PointXYZ>::Ptr scene = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::PointCloud<pcl::PointXYZ>::Ptr scene_keypoints = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::PointCloud<pcl::PointNormal>::Ptr scene_keypoints_with_normals = pcl::PointCloud<pcl::PointNormal>::Ptr(new pcl::PointCloud<pcl::PointNormal>());

	std::cout << "Step 3: Capture Point Cloud\n";
	mtx.lock();
	pcl::copyPointCloud(*latestCloud, *captured_scene);
	pcl::copyPointCloud(*latestCloud, *colored_scene);
	mtx.unlock();
	pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(colored_scene);

	customViewer.viewer->removeAllShapes();
	customViewer.viewer->removeAllPointClouds();
	customViewer.viewer->addPointCloud<pcl::PointXYZRGB>(colored_scene, rgb, "colored_scene");
	customViewer.viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "colored_scene");
	std::getchar();

	// --------------------------------------------  Preprocess--------------------------------------------------------------
	std::cout << "Step 4: Remove background\n";
	tt.tic();
	sacsegmentation_extindices(captured_scene, 0.005, segmented_scene); // RANSAC Segmentation and remove biggest plane (table)
	cout << "Remove background in " << tt.toc() << " mseconds..." << std::endl;

	*scene = *segmented_scene;

	if (scene->size() == 0)
	{
		std::cout << "No point left in scene. Skipping this frame ..." << std::endl;
		return;
	}
	customViewer.viewer->removeAllShapes();
	customViewer.viewer->removeAllPointClouds();
	customViewer.viewer->addPointCloud(scene);
	std::getchar();


	// -----------------------------------------Voxel grid ------------------------------------------------------
	std::cout << "Step 5: Voxel Grid and Remove Outliner:" << std::endl;
	tt.tic();
	pcl::VoxelGrid<pcl::PointXYZ> vg_;
	vg_.setInputCloud(scene);
	vg_.setLeafSize(0.001f, 0.001f, 0.001f);
	vg_.setDownsampleAllData(true);
	vg_.filter(*scene_keypoints);
	statisticalOutlinerRemoval(scene_keypoints, 50, scene_keypoints);// 50 k-neighbors noise removal

	pcl::VoxelGrid<pcl::PointXYZ> vg;
	vg.setInputCloud(scene_keypoints);
	vg.setLeafSize(samp_rad, samp_rad, samp_rad);
	vg.setDownsampleAllData(true);
	vg.filter(*scene_keypoints);
	std::cout << " Voxel-grid filtered from size " << scene->points.size() << " to " << scene_keypoints->points.size() << std::endl;

	cout << "Voxel-grid filtered in " << tt.toc() << " mseconds..." << std::endl;

	
	customViewer.viewer->removeAllShapes();
	customViewer.viewer->removeAllPointClouds();
	customViewer.viewer->addPointCloud(scene_keypoints);
	std::getchar();

	// -----------------------------------------Normals ------------------------------------------------------
	tt.tic();
	std::cout << "Step 6: Calculate normals (using unfilter cloud as surface)\n";
	pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
	pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
	// Calculate all the normals of the entire surface
	ne.setInputCloud(scene_keypoints);
	ne.setSearchSurface(scene);
	ne.setNumberOfThreads(8);
	ne.setSearchMethod(tree);
	ne.setRadiusSearch(norm_rad);
	ne.compute(*normals);

	pcl::concatenateFields(*scene_keypoints, *normals, *scene_keypoints_with_normals);
	cout << "Calculated normals in " << tt.toc() << " mseconds..." << std::endl;
	customViewer.viewer->removeAllShapes();
	customViewer.viewer->removeAllPointClouds();
	customViewer.viewer->addPointCloudNormals<pcl::PointNormal, pcl::PointNormal>(scene_keypoints_with_normals, scene_keypoints_with_normals, 1, 0.005, "scene_keypoints_with_normals");
	std::getchar();

/*这段代码是一个点云配准的过程，主要使用了PPF（Point Pair Features）算法。下面是代码的主要步骤：
创建一个PPFRegistration对象ppf_registration，用于点云配准。
设置PPF配准过程的参数，包括场景参考点采样率、场景参考点采样率、Lvoxel（体素大小）和搜索方法。
设置输入源点云和目标点云，即模型关键点云和场景关键点云。
创建一个PoseWithVotesList对象results，用于存储计算得到的最终位姿。
调用ppf_registration的computeFinalPoses方法，计算最终的位姿。
清空可视化窗口中的形状和点云。
将彩色场景点云添加到可视化窗口，并设置点云的大小。
遍历计算得到的位姿列表results，为每个实例生成点云。
设置实例点云的颜色和大小，并将其添加到可视化窗口中。
根据位姿变换矩阵，生成表示坐标轴的点云，并将其添加到可视化窗口中。
设置坐标轴的线宽。
最后，等待用户按下任意键。
这段代码的作用是将模型点云与场景点云进行配准，并在可视化窗口中显示配准结果*/
	// -------------------------------------------------PPF ---------------------------------------------
	std::cout << "Step 7: PPF\n";
	tt.tic();
	pcl::MyPPFRegistration<pcl::PointNormal, pcl::PointNormal> ppf_registration;
	// set parameters for the PPF registration procedure
	ppf_registration.setSceneReferencePointSamplingRate(scene_reference_point_sampling_rate);
	ppf_registration.setSceneReferredPointSamplingRate(scene_referred_point_sampling_rate);
	ppf_registration.setLvoxel(Lvoxel);
	ppf_registration.setSearchMethod(ppf_hashmap_search);
	ppf_registration.setInputSource(model_keypoints_with_normals);
	ppf_registration.setInputTarget(scene_keypoints_with_normals);

	typename pcl::MyPPFRegistration<pcl::PointNormal, pcl::PointNormal>::PoseWithVotesList results;
	ppf_registration.computeFinalPoses(results);
	cout << "PPF Scene Calculation in " << tt.toc() << " mseconds..." << std::endl;
	customViewer.viewer->removeAllShapes();
	customViewer.viewer->removeAllPointClouds();
	
	customViewer.viewer->addPointCloud<pcl::PointXYZRGB>(colored_scene, rgb, "colored_scene");
	customViewer.viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "colored_scene");
	//Draw new Matched model-scene
	for (size_t results_i = 0; results_i < results.size(); ++results_i)
	{
		// Generates clouds for each instances found
		pcl::PointCloud<pcl::PointXYZ>::Ptr instance(new pcl::PointCloud<pcl::PointXYZ>());
		pcl::transformPointCloud(*model_keypoints, *instance, results[results_i].pose);
		std::stringstream ss_instance;
		ss_instance << "instance_" << results_i;

		CloudStyle clusterStyle = style_green;
		pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> instance_color_handler(instance, clusterStyle.r, clusterStyle.g, clusterStyle.b);
		customViewer.viewer->addPointCloud(instance, instance_color_handler, ss_instance.str());
		customViewer.viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, clusterStyle.size, ss_instance.str());
		
		Eigen::Matrix4f transform = results[results_i].pose.matrix();
		pcl::PointCloud<pcl::PointXYZ> Oz;
		Oz.push_back(pcl::PointXYZ(0, 0, 0));
		Oz.push_back(pcl::PointXYZ(0, 0, 0.05));
		pcl::transformPointCloud(Oz, Oz, transform);
		if (Oz[1].z - Oz[0].z < 0)
		{
			Eigen::Matrix4f rotx180;
			rotx180 << 1, 0, 0, 0,
				0, -1, 0, 0,
				0, 0, -1, 0,
				0, 0, 0, 1;
			transform = transform * rotx180;
		}


		pcl::PointCloud<pcl::PointXYZ> Oxyz;
		Oxyz.push_back(pcl::PointXYZ(0, 0, 0));
		Oxyz.push_back(pcl::PointXYZ(0.05, 0, 0));
		Oxyz.push_back(pcl::PointXYZ(0, 0.05, 0));
		Oxyz.push_back(pcl::PointXYZ(0, 0, 0.05));
		pcl::transformPointCloud(Oxyz, Oxyz, transform);

		customViewer.viewer->addLine<pcl::PointXYZ, pcl::PointXYZ>(Oxyz[0], Oxyz[1], 255, 0, 0, ss_instance.str() + "x");
		customViewer.viewer->addLine<pcl::PointXYZ, pcl::PointXYZ>(Oxyz[0], Oxyz[2], 0, 255, 0, ss_instance.str() + "y");
		customViewer.viewer->addLine<pcl::PointXYZ, pcl::PointXYZ>(Oxyz[0], Oxyz[3], 0, 0, 255, ss_instance.str() + "z");
		customViewer.viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 3, ss_instance.str() + "x");
		customViewer.viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 3, ss_instance.str() + "y");
		customViewer.viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 3, ss_instance.str() + "z");
	}
	std::getchar();

/*这段代码是一个姿态验证的步骤，用于过滤掉异常值并获得更精确的结果。代码中的注释提到了这一点。
首先，代码输出了一个提示信息："Step 8: Pose Verification"，然后开始计时。
接下来，定义了一个名为"verified_results"的变量，
类型为"typename pcl::MyPPFRegistration<pcl::PointNormal, pcl::PointNormal>::PoseWithVotesList"，用于存储验证后的姿态结果。
然后，调用了"ppf_registration.verifyPoses(results, verified_results)"函数，对结果进行姿态验证。
接下来，代码清空了可视化窗口中的所有形状和点云。
然后，将彩色场景点云添加到可视化窗口中，并设置点云的渲染属性。
接下来，使用一个循环遍历"verified_results"中的每个姿态结果。
在循环中，首先根据姿态结果生成一个实例点云。
然后，为实例点云设置颜色，并将其添加到可视化窗口中。
接下来，根据姿态结果的变换矩阵，计算出Oz和Oxyz两个点云。
然后，根据Oz和Oxyz的坐标变换，将它们变换到正确的位置。
接下来，将Oxyz的三条边添加到可视化窗口中，并设置线的颜色和宽度。
循环结束后，代码等待用户按下任意键。
最后，准备将结果写入文件"../../data/result/scene.txt"。
这段代码的作用是对姿态结果进行验证，并将验证后的结果可视化，并将结果写入文件。*/

	// -------------------------------------- Pose Verification ------------------------------------------------
	// Verify poses for filtering out outliers and obtaining more precise results
	std::cout << "Step 8: Pose Verification\n";
	tt.tic();
	typename pcl::MyPPFRegistration<pcl::PointNormal, pcl::PointNormal>::PoseWithVotesList verified_results;
    ppf_registration.verifyPoses (results, verified_results);
	cout << "Pose Verification in " << tt.toc() << " mseconds..." << std::endl;
	customViewer.viewer->removeAllShapes();
	customViewer.viewer->removeAllPointClouds();
	
	customViewer.viewer->addPointCloud<pcl::PointXYZRGB>(colored_scene, rgb, "colored_scene");
	customViewer.viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "colored_scene");
	//Draw new Matched model-scene
	for (size_t results_i = 0; results_i < verified_results.size(); ++results_i)
	{
		// Generates clouds for each instances found
		pcl::PointCloud<pcl::PointXYZ>::Ptr instance(new pcl::PointCloud<pcl::PointXYZ>());
		pcl::transformPointCloud(*model_keypoints, *instance, verified_results[results_i].pose);
		std::stringstream ss_instance;
		ss_instance << "instance_" << results_i;

		CloudStyle clusterStyle = style_green;
		pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> instance_color_handler(instance, clusterStyle.r, clusterStyle.g, clusterStyle.b);
		customViewer.viewer->addPointCloud(instance, instance_color_handler, ss_instance.str());
		customViewer.viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, clusterStyle.size, ss_instance.str());
		
		Eigen::Matrix4f transform = verified_results[results_i].pose.matrix();
		pcl::PointCloud<pcl::PointXYZ> Oz;
		Oz.push_back(pcl::PointXYZ(0, 0, 0));
		Oz.push_back(pcl::PointXYZ(0, 0, 0.05));
		pcl::transformPointCloud(Oz, Oz, transform);
		if (Oz[1].z - Oz[0].z < 0)
		{
			Eigen::Matrix4f rotx180;
			rotx180 << 1, 0, 0, 0,
				0, -1, 0, 0,
				0, 0, -1, 0,
				0, 0, 0, 1;
			transform = transform * rotx180;
		}


		pcl::PointCloud<pcl::PointXYZ> Oxyz;
		Oxyz.push_back(pcl::PointXYZ(0, 0, 0));
		Oxyz.push_back(pcl::PointXYZ(0.05, 0, 0));
		Oxyz.push_back(pcl::PointXYZ(0, 0.05, 0));
		Oxyz.push_back(pcl::PointXYZ(0, 0, 0.05));
		pcl::transformPointCloud(Oxyz, Oxyz, transform);

		customViewer.viewer->addLine<pcl::PointXYZ, pcl::PointXYZ>(Oxyz[0], Oxyz[1], 255, 0, 0, ss_instance.str() + "x");
		customViewer.viewer->addLine<pcl::PointXYZ, pcl::PointXYZ>(Oxyz[0], Oxyz[2], 0, 255, 0, ss_instance.str() + "y");
		customViewer.viewer->addLine<pcl::PointXYZ, pcl::PointXYZ>(Oxyz[0], Oxyz[3], 0, 0, 255, ss_instance.str() + "z");
		customViewer.viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 3, ss_instance.str() + "x");
		customViewer.viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 3, ss_instance.str() + "y");
		customViewer.viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 3, ss_instance.str() + "z");
	}
	std::getchar();

	
	//Prepare to write down the results
	std::ofstream file("../../lwhdata/result/scene.txt");
	if(file){
		std::cout<<"open the result file"<<endl;
	}else{
		std::cout<<"can't open the result file"<<endl;
	}
/*这段代码是一个三维物体匹配的程序，主要用于将一个三维模型与一个三维场景进行匹配。
程序首先输出一段文字，然后开始计时。接着，程序会遍历所有已验证的匹配结果，对于每个匹配结果，程序会生成一个点云，
并将模型变换到匹配结果的位置。然后，程序会使用ICP算法对点云进行细化，以便更好地匹配场景中的点云。
程序会输出每个实例的匹配结果，并将结果写入文件。最后，程序会将匹配结果可视化，并输出总的匹配时间。*/
	//----------------------------------------------------------- ICP ----------------------------------------------------
	std::cout << "Step 9: Refine only the visible points from the result poses using ICP.\n";
	tt.tic();
	std::vector<pcl::PointCloud<pcl::PointXYZ>::ConstPtr> instances;
	for (size_t results_i = 0; results_i < verified_results.size(); ++results_i)
	{
		// Generates clouds for each instances found
		pcl::PointCloud<pcl::PointXYZ>::Ptr instance(new pcl::PointCloud<pcl::PointXYZ>());
		pcl::transformPointCloud(*model, *instance, verified_results[results_i].pose);

		std::vector<float> camera_pos = { 0, 0 ,0 };
		HPR(instance, camera_pos, 3, instance);

		pcl::VoxelGrid<pcl::PointXYZ> vg_icp;
		vg_icp.setInputCloud(instance);
		vg_icp.setLeafSize(samp_rad, samp_rad, samp_rad);
		vg_icp.setDownsampleAllData(true);
		vg_icp.filter(*instance);

		pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
		icp.setMaximumIterations(icp_max_iter_);
		icp.setMaxCorrespondenceDistance(icp_corr_distance_);
		icp.setInputTarget(scene_keypoints);
		icp.setInputSource(instance);
		pcl::PointCloud<pcl::PointXYZ>::Ptr registered_instance(new pcl::PointCloud<pcl::PointXYZ>);
		icp.align(*registered_instance);

		std::cout << "Instance " << results_i << " ";
		if (icp.hasConverged())
		{
			std::cout << "Aligned!" << std::endl;
		}
		else
		{
			std::cout << "Not Aligned!" << std::endl;
		}

		Eigen::Matrix4f transformation = icp.getFinalTransformation();
		transformation = transformation * verified_results[results_i].pose.matrix();
        std::cout<<results_i<<endl;
		std::cout<<transformation<<endl;
		file << "Instance " << results_i << std::endl << transformation << '\n';

		pcl::transformPointCloud(*model_keypoints, *instance, transformation);
		instances.push_back(instance);
	}
	cout << "ICP in " << tt.toc() << " mseconds..." << std::endl;
	cout << "instances size: " << instances.size()	 << std::endl;


	
	// -------------------------------------------------------- Visualization --------------------------------------------------------
	tt.tic();
	if (!customViewer.viewer->wasStopped()) {
		customViewer.viewer->removeAllShapes();
		customViewer.viewer->removeAllPointClouds();

		customViewer.viewer->addPointCloud<pcl::PointXYZRGB>(colored_scene, rgb, "colored_scene");
		customViewer.viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "colored_scene");

		//Draw new Matched model-scene
		for (std::size_t i = 0; i < instances.size(); ++i)
		{
			std::stringstream ss_instance;
			ss_instance << "instance_" << i;

			CloudStyle clusterStyle = style_green;
			pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> instance_color_handler(instances[i], clusterStyle.r, clusterStyle.g, clusterStyle.b);
			customViewer.viewer->addPointCloud(instances[i], instance_color_handler, ss_instance.str());
			customViewer.viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, clusterStyle.size, ss_instance.str());
		}	
	}

	cout << "Visualize in " << tt.toc() << " mseconds..." << std::endl;

	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
	cout << "TOTAL 3D MATCHING TIME: " << duration.count() << " mseconds!!" << endl; 
}