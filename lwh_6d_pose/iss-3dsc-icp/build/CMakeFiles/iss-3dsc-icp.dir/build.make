# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lwh/6d_pose/iss-3dsc-icp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lwh/6d_pose/iss-3dsc-icp/build

# Include any dependencies generated for this target.
include CMakeFiles/iss-3dsc-icp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/iss-3dsc-icp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/iss-3dsc-icp.dir/flags.make

CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.o: CMakeFiles/iss-3dsc-icp.dir/flags.make
CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lwh/6d_pose/iss-3dsc-icp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.o -c /home/lwh/6d_pose/iss-3dsc-icp/src/main.cpp

CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lwh/6d_pose/iss-3dsc-icp/src/main.cpp > CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.i

CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lwh/6d_pose/iss-3dsc-icp/src/main.cpp -o CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.s

CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.o: CMakeFiles/iss-3dsc-icp.dir/flags.make
CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.o: ../src/Registration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lwh/6d_pose/iss-3dsc-icp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.o -c /home/lwh/6d_pose/iss-3dsc-icp/src/Registration.cpp

CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lwh/6d_pose/iss-3dsc-icp/src/Registration.cpp > CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.i

CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lwh/6d_pose/iss-3dsc-icp/src/Registration.cpp -o CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.s

CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.o: CMakeFiles/iss-3dsc-icp.dir/flags.make
CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.o: ../src/KeyPointsAnd3DSC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lwh/6d_pose/iss-3dsc-icp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.o -c /home/lwh/6d_pose/iss-3dsc-icp/src/KeyPointsAnd3DSC.cpp

CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lwh/6d_pose/iss-3dsc-icp/src/KeyPointsAnd3DSC.cpp > CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.i

CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lwh/6d_pose/iss-3dsc-icp/src/KeyPointsAnd3DSC.cpp -o CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.s

# Object files for target iss-3dsc-icp
iss__3dsc__icp_OBJECTS = \
"CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.o" \
"CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.o" \
"CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.o"

# External object files for target iss-3dsc-icp
iss__3dsc__icp_EXTERNAL_OBJECTS =

iss-3dsc-icp: CMakeFiles/iss-3dsc-icp.dir/src/main.cpp.o
iss-3dsc-icp: CMakeFiles/iss-3dsc-icp.dir/src/Registration.cpp.o
iss-3dsc-icp: CMakeFiles/iss-3dsc-icp.dir/src/KeyPointsAnd3DSC.cpp.o
iss-3dsc-icp: CMakeFiles/iss-3dsc-icp.dir/build.make
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_apps.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_outofcore.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_people.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_system.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_regex.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libqhull.so
iss-3dsc-icp: /usr/lib/libOpenNI.so
iss-3dsc-icp: /usr/lib/libOpenNI2.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkChartsCore-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkInfovisCore-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libfreetype.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libz.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libjpeg.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpng.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libtiff.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libexpat.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkIOGeometry-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkIOLegacy-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkIOPLY-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkRenderingLOD-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkViewsContext2D-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkViewsCore-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkRenderingContextOpenGL2-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkRenderingOpenGL2-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libflann_cpp.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_system.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_thread.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_surface.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_keypoints.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_tracking.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_recognition.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_registration.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_stereo.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_segmentation.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_features.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_filters.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_sample_consensus.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_ml.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_visualization.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_search.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_kdtree.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_io.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_octree.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpcl_common.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_system.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_regex.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libqhull.so
iss-3dsc-icp: /usr/lib/libOpenNI.so
iss-3dsc-icp: /usr/lib/libOpenNI2.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libjpeg.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libpng.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libtiff.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libexpat.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_thread.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkInteractionWidgets-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkFiltersModeling-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkInteractionStyle-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkFiltersExtraction-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkFiltersStatistics-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkImagingFourier-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkalglib-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkFiltersHybrid-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkImagingGeneral-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkImagingSources-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkImagingHybrid-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkRenderingAnnotation-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkImagingColor-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkRenderingVolume-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkIOXML-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkIOXMLParser-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkIOCore-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkRenderingContext2D-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkRenderingFreeType-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libfreetype.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkImagingCore-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkRenderingCore-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkCommonColor-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeometry-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkFiltersSources-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeneral-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkCommonComputationalGeometry-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkFiltersCore-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkIOImage-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkCommonExecutionModel-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkCommonDataModel-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkCommonTransforms-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkCommonMisc-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkCommonMath-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkCommonSystem-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkCommonCore-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtksys-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkDICOMParser-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libvtkmetaio-7.1.so.7.1p.1
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libz.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libGLEW.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libSM.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libICE.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libX11.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libXext.so
iss-3dsc-icp: /usr/lib/x86_64-linux-gnu/libXt.so
iss-3dsc-icp: CMakeFiles/iss-3dsc-icp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lwh/6d_pose/iss-3dsc-icp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable iss-3dsc-icp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iss-3dsc-icp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/iss-3dsc-icp.dir/build: iss-3dsc-icp

.PHONY : CMakeFiles/iss-3dsc-icp.dir/build

CMakeFiles/iss-3dsc-icp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/iss-3dsc-icp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/iss-3dsc-icp.dir/clean

CMakeFiles/iss-3dsc-icp.dir/depend:
	cd /home/lwh/6d_pose/iss-3dsc-icp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lwh/6d_pose/iss-3dsc-icp /home/lwh/6d_pose/iss-3dsc-icp /home/lwh/6d_pose/iss-3dsc-icp/build /home/lwh/6d_pose/iss-3dsc-icp/build /home/lwh/6d_pose/iss-3dsc-icp/build/CMakeFiles/iss-3dsc-icp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/iss-3dsc-icp.dir/depend
