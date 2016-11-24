cmake_minimum_required(VERSION 2.8.8)
set(MODULE_NAME leetcode)

project(${MODULE_NAME} CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB HDRS CMAKE_CURRENT_SOURCE_DIR *h)
set(SRCS main.cpp)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${MODULE_NAME})

add_executable(${MODULE_NAME} ${SRCS} ${HDRS})
