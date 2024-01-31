cmake_minimum_required(VERSION 2.6)
project(KD-ICP)
 
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
FIND_PACKAGE(Boost REQUIRED COMPONENTS system filesystem thread)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_INCLUDE_DIRS})

add_executable(KD-ICP src/main.cpp)
target_link_libraries (KD-ICP ${PCL_LIBRARIES} ${Boost_LIBRARIES})


install(TARGETS KD-ICP RUNTIME DESTINATION bin)

