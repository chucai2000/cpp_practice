cmake_minimum_required(VERSION 3.6.0)
project(cpp_practice CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies)

include_directories(${DEPENDENCIES_DIR}/include)
link_directories(${DEPENDENCIES_DIR}/lib)

enable_testing()

add_subdirectory(leetcode)
add_subdirectory(stackoverflow)
add_subdirectory(interview)

