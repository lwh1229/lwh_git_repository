cmake_minimum_required(VERSION 2.6)
project(3dsc-ICP)
 
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
FIND_PACKAGE(Boost REQUIRED COMPONENTS system filesystem thread)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_INCLUDE_DIRS})

add_executable(3dsc-ICP src/main.cpp)
target_link_libraries (3dsc-ICP ${PCL_LIBRARIES} ${Boost_LIBRARIES})


install(TARGETS 3dsc-ICP RUNTIME DESTINATION bin)

