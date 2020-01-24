# CMake Project Settings for MiniHawk Gazebo Simulation 

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(minihawk_behavioral SHARED script/minihawk_behavioral.cpp)
target_link_libraries(minihawk_behavioral ${GAZEBO_LIBRARIES})
