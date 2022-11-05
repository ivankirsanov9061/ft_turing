cmake_minimum_required(VERSION 3.23)
project(unit_test)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
find_package(GTest REQUIRED)

add_executable(unit_test main.cpp)

target_link_libraries(unit_test gtest gtest_main)
