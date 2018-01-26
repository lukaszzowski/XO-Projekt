cmake_minimum_required (VERSION 2.8.9)
project(XO)
enable_testing()
add_executable (XO main.cpp game.cpp game.h)
add_definitions(-std=c++11)

#GTEST UNIT TESTING
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(runTest main_test.cpp game.cpp)
target_link_libraries(runTest gtest gtest_main pthread)
add_test(runTest runTest)