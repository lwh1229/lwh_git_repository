cmake_minimum_required(VERSION 2.6)
project(3d-ndt)
 
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
FIND_PACKAGE(Boost REQUIRED COMPONENTS system filesystem thread)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_INCLUDE_DIRS})

add_executable(3d-ndt src/main.cpp)
target_link_libraries (3d-ndt ${PCL_LIBRARIES} ${Boost_LIBRARIES})



