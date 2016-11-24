cmake_minimum_required(VERSION 2.8.8)
project(CMakeCodes CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
add_subdirectory(leetcode)
add_subdirectory(stackoverflow)
add_subdirectory(interview)

