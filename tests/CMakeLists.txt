cmake_minimum_required(VERSION 3.23)
project(tests)

set(CMAKE_CXX_STANDARD 20)

if (UNIT_TESTS)
    add_subdirectory(unit)
endif ()
