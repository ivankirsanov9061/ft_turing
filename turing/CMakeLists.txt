cmake_minimum_required(VERSION 3.23)
project(turing)

set(CMAKE_CXX_STANDARD 20)

message("$CMAKE_SOURCE_DIR $(CMAKE_SOURCE_DIR)")

add_executable(turing
        ${CMAKE_SOURCE_DIR}/turing/main.cpp
        ${CMAKE_SOURCE_DIR}/turing/SafeStreamWriter/SafeStreamWriter.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/ParseArguments.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/HelpArgument.cpp)

target_include_directories(turing PRIVATE
        ${CMAKE_SOURCE_DIR}/turing/SafeStreamWriter
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments)
