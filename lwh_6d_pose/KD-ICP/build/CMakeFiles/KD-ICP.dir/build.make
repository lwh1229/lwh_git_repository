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
CMAKE_SOURCE_DIR = /home/lwh/6d_pose/KD-ICP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lwh/6d_pose/KD-ICP/build

# Include any dependencies generated for this target.
include CMakeFiles/KD-ICP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KD-ICP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KD-ICP.dir/flags.make

CMakeFiles/KD-ICP.dir/src/main.cpp.o: CMakeFiles/KD-ICP.dir/flags.make
CMakeFiles/KD-ICP.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lwh/6d_pose/KD-ICP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KD-ICP.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KD-ICP.dir/src/main.cpp.o -c /home/lwh/6d_pose/KD-ICP/src/main.cpp

CMakeFiles/KD-ICP.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KD-ICP.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lwh/6d_pose/KD-ICP/src/main.cpp > CMakeFiles/KD-ICP.dir/src/main.cpp.i

CMakeFiles/KD-ICP.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KD-ICP.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lwh/6d_pose/KD-ICP/src/main.cpp -o CMakeFiles/KD-ICP.dir/src/main.cpp.s

# Object files for target KD-ICP
KD__ICP_OBJECTS = \
"CMakeFiles/KD-ICP.dir/src/main.cpp.o"

# External object files for target KD-ICP
KD__ICP_EXTERNAL_OBJECTS =

KD-ICP: CMakeFiles/KD-ICP.dir/src/main.cpp.o
KD-ICP: CMakeFiles/KD-ICP.dir/build.make
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_apps.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_outofcore.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_people.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_system.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_regex.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libqhull.so
KD-ICP: /usr/lib/libOpenNI.so
KD-ICP: /usr/lib/libOpenNI2.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkChartsCore-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkInfovisCore-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libfreetype.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libz.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libjpeg.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpng.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libtiff.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libexpat.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkIOGeometry-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkIOLegacy-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkIOPLY-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkRenderingLOD-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkViewsContext2D-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkViewsCore-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkRenderingContextOpenGL2-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkRenderingOpenGL2-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libflann_cpp.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_system.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_thread.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_surface.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_keypoints.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_tracking.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_recognition.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_registration.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_stereo.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_segmentation.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_features.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_filters.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_sample_consensus.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_ml.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_visualization.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_search.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_kdtree.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_io.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_octree.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpcl_common.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_system.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_regex.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libqhull.so
KD-ICP: /usr/lib/libOpenNI.so
KD-ICP: /usr/lib/libOpenNI2.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libjpeg.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libpng.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libtiff.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libexpat.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_thread.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkInteractionWidgets-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkFiltersModeling-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkInteractionStyle-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkFiltersExtraction-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkFiltersStatistics-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkImagingFourier-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkalglib-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkFiltersHybrid-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkImagingGeneral-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkImagingSources-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkImagingHybrid-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkRenderingAnnotation-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkImagingColor-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkRenderingVolume-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkIOXML-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkIOXMLParser-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkIOCore-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkRenderingContext2D-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkRenderingFreeType-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libfreetype.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkImagingCore-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkRenderingCore-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkCommonColor-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeometry-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkFiltersSources-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeneral-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkCommonComputationalGeometry-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkFiltersCore-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkIOImage-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkCommonExecutionModel-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkCommonDataModel-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkCommonTransforms-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkCommonMisc-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkCommonMath-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkCommonSystem-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkCommonCore-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtksys-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkDICOMParser-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libvtkmetaio-7.1.so.7.1p.1
KD-ICP: /usr/lib/x86_64-linux-gnu/libz.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libGLEW.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libSM.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libICE.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libX11.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libXext.so
KD-ICP: /usr/lib/x86_64-linux-gnu/libXt.so
KD-ICP: CMakeFiles/KD-ICP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lwh/6d_pose/KD-ICP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KD-ICP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KD-ICP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KD-ICP.dir/build: KD-ICP

.PHONY : CMakeFiles/KD-ICP.dir/build

CMakeFiles/KD-ICP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KD-ICP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KD-ICP.dir/clean

CMakeFiles/KD-ICP.dir/depend:
	cd /home/lwh/6d_pose/KD-ICP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lwh/6d_pose/KD-ICP /home/lwh/6d_pose/KD-ICP /home/lwh/6d_pose/KD-ICP/build /home/lwh/6d_pose/KD-ICP/build /home/lwh/6d_pose/KD-ICP/build/CMakeFiles/KD-ICP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KD-ICP.dir/depend
