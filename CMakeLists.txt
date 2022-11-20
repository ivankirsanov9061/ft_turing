cmake_minimum_required(VERSION 3.23)
project(ft_turing)

set(CXX_VERSION 20)

set(CMAKE_CXX_STANDARD ${CXX_VERSION})

add_subdirectory(turing)

if (TESTS)
    add_subdirectory(tests)
endif ()
