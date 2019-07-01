cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(octree_compressor)

set(PCL_DIR "/home/vitor/pcl-pcl-1.9.1/build/")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/" ${CMAKE_MODULE_PATH})
set(VTK_DIR "/home/vitor/VTK-7.1.1/build/")

find_package(PCL 1.9.1 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(octree_compressor octree_compressor.cpp)
target_link_libraries (octree_compressor ${PCL_LIBRARIES})
