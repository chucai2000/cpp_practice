cmake_minimum_required(VERSION 3.6.0)
set(MODULE_NAME leetcode)

project(${MODULE_NAME} CXX)

file(GLOB HDRS CMAKE_CURRENT_SOURCE_DIR *h)
file(GLOB SRCS CMAKE_CURRENT_SOURCE_DIR *.cpp)

add_executable(${MODULE_NAME} ${SRCS} ${HDRS})
target_link_libraries(${MODULE_NAME} gtest gmock gtest_main gmock_main)
add_test(test_${MODULE_NAME} ${MODULE_NAME})
