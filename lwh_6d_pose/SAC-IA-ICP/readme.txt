https://blog.csdn.net/peach_blossom/article/details/78506184?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-78506184-blog-116606641.235%5Ev40%5Epc_relevant_rights_sort&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-78506184-blog-116606641.235%5Ev40%5Epc_relevant_rights_sort&utm_relevant_index=2



ICP（Iterative Closest Point）配准算法是一种常用的点云配准算法，它通过迭代求解最佳的旋转和平移变换，将源点云对齐到目标点云上。ICP算法的目标是通过最小化两个点云之间的距离来获取最佳的变换矩阵。

在传统的ICP算法中，只使用源点云和目标点云进行配准，而不考虑其他的信息。ICP算法的核心思想是通过最小化两个点云之间的距离来找到最佳的对应关系。然而，在某些情况下，ICP算法可能会收敛到局部最优解，即找到的变换矩阵并不能完全对齐两个点云。

为了解决这个问题，我们可以先使用SAC（Sample Consensus）配准算法来获取一个较好的初始变换矩阵，再使用ICP算法进行进一步的细化配准。SAC配准算法是一种基于采样一致性的配准算法，它能够鲁棒地估计初始变换矩阵，但精度可能不够高。因此，将SAC配准的结果作为ICP配准的初始值，可以提高ICP算法的配准效果。

在代码中，使用icp.setInputSource(cloud_src)将源点云设置为ICP的输入，icp.setInputTarget(cloud_tgt_o)将目标点云设置为ICP的目标。然后，使用SAC配准的结果sac_trans作为初始变换矩阵，调用icp.align(*icp_result, sac_trans)执行ICP算法进行配准。

综上所述，ICP配准使用源点云和目标点云进行配准，再使用SAC配准的结果作为初始变换矩阵，可以提高配准的精度和鲁棒性。
