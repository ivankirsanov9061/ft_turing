cmake_minimum_required(VERSION 3.23)
project(unit_tests)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
find_package(GTest REQUIRED)

add_executable(unit_tests
        ${CMAKE_SOURCE_DIR}/tests/unit/IsHelpArgumentGiven.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/ParseArguments.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/HelpArgument.cpp
        ${CMAKE_SOURCE_DIR}/turing/SafeStreamWriter/SafeStreamWriter.cpp)

target_include_directories(unit_tests PRIVATE
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments
        ${CMAKE_SOURCE_DIR}/turing/SafeStreamWriter)

target_link_libraries(unit_tests gtest gtest_main)
