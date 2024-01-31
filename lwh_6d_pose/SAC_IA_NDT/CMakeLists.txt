cmake_minimum_required(VERSION 2.6)
project(SCA-IA-NDT)
 
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
FIND_PACKAGE(Boost REQUIRED COMPONENTS system filesystem thread)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_INCLUDE_DIRS})

add_executable(SCA-IA-NDT src/main.cpp)
target_link_libraries (SCA-IA-NDT ${PCL_LIBRARIES} ${Boost_LIBRARIES})


install(TARGETS SCA-IA-NDT RUNTIME DESTINATION bin)

