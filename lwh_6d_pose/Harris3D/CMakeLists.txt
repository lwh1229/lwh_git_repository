cmake_minimum_required(VERSION 2.6)
project(Harris3D)
 
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
FIND_PACKAGE(Boost REQUIRED COMPONENTS system filesystem thread)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_INCLUDE_DIRS})

add_executable(Harris3D src/main.cpp)
target_link_libraries (Harris3D ${PCL_LIBRARIES} ${Boost_LIBRARIES})


install(TARGETS Harris3D RUNTIME DESTINATION bin)

