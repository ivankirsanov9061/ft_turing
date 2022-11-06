cmake_minimum_required(VERSION 3.23)
project(ft_turing)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(turing)

if (TESTS)
    add_subdirectory(tests)
endif ()
