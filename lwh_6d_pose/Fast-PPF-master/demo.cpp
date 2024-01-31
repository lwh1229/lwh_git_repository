//Author: Khuong Thanh Gia Hieu
//Viet Nam - Bach Khoa University - CK16KSCD
/*这段代码是一个使用PPF（Point Pair Feature）描述符进行物体姿态估计的项目。代码的作者是Khuong Thanh Gia Hieu，来自越南的Bach Khoa大学CK16KSCD班级。

代码的主要内容如下：
引入头文件和库：包括PPF.h头文件以及thread和mutex库。

主函数：程序的入口函数。

创建PPF描述符对象：使用new关键字创建一个DescriptorPPF对象，并输出描述符类型。
加载模型：设置模型路径为"../data/model/bi/6914.STL"，并输出"Done Preparation ... !"。
加载场景：使用pcl库加载点云文件"../data/scene/bi/scene0.pcd"，如果加载失败则输出错误信息并返回-1。
存储最新的点云数据：调用descr对象的storeLatestCloud函数，将加载的点云数据存储起来。
多线程处理和可视化：为了避免程序崩溃，需要使用不同的线程进行处理和可视化。
处理线程：定义一个lambda函数_3D_Matching_Lambda，其中调用descr对象的prepareModelDescriptor和_3D_Matching函数，
表示进行模型描述符的准备和3D匹配操作。
可视化线程：使用while循环，当自定义的可视化窗口没有被关闭时，调用descr对象的customViewer.viewer的spinOnce函数进行可视化，
并通过std::this_thread::sleep_for函数设置300毫秒的延迟。
等待处理线程结束：使用if语句判断_3D_Matching_Thread是否可加入(joinable)，如果是，则等待处理线程结束。
返回0：表示程序正常结束。
这段代码的功能是加载模型和场景，使用PPF描述符进行物体姿态估计，并通过多线程进行处理和可视化。*/
#include "PPF.h"
#include <thread>
#include <mutex>

int main()
{
	//In this project, we use PPF Descriptor from this paper, please read before continue:
	//Fast and Robust Pose Estimation Algorithm for Bin Picking Using Point Pair Feature
    //Mingyu Li and Koichi Hashimoto 
	//International Conference on Pattern Recognition (ICPR)
	DescriptorPPF* descr(new DescriptorPPF());
	std::cout << "Descriptor type: " << descr->getType() << endl;
	
	//Load model
	descr->setModelPath("../lwhdata/model/target.stl");
	std::cout << "Done Preparation ... !" << std::endl;

	//Load scene
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
	if (pcl::io::loadPCDFile<pcl::PointXYZRGBA> ("../lwhdata/scene/newscene.pcd", *cloud) == -1) //* load the file
    {
		PCL_ERROR ("Couldn't read file\n");
		return (-1);
    }
	descr->storeLatestCloud(cloud);

	//We MUST process and visualize from different thread, or the program will crash

	// Start processing from different thread
	auto _3D_Matching_Lambda = [&descr]() {
		descr->prepareModelDescriptor();
		descr->_3D_Matching();
	};
	std::thread _3D_Matching_Thread(_3D_Matching_Lambda);
	std::cout << "Processing Thread Started ... !" << std::endl;
	
	// Start visualizing from different thread
	while (!descr->customViewer.viewer->wasStopped()) {
		descr->customViewer.viewer->spinOnce(300);
		std::this_thread::sleep_for(std::chrono::microseconds(300000));
	}
	 
	//Wait for thread to finish before closing the program
	if (_3D_Matching_Thread.joinable())
		_3D_Matching_Thread.join();

	return 0;

}