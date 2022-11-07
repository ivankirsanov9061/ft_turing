cmake_minimum_required(VERSION 3.23)
project(turing)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

add_executable(turing
        ${CMAKE_SOURCE_DIR}/turing/main.cpp
        ${CMAKE_SOURCE_DIR}/turing/SafeStreamWriter/SafeStreamWriter.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/ParseArguments.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/HelpArgument.cpp
        ${CMAKE_SOURCE_DIR}/turing/JSONHandler/Handler.cpp
        ${CMAKE_SOURCE_DIR}/turing/JSONHandler/Reader.cpp
        ${CMAKE_SOURCE_DIR}/turing/JSONHandler/MachineDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/JSONHandler/MachineDescriptions/Alphabet.cpp
        ${CMAKE_SOURCE_DIR}/turing/JSONHandler/MachineDescriptions/Finals.cpp
        ${CMAKE_SOURCE_DIR}/turing/JSONHandler/MachineDescriptions/States.cpp
        ${CMAKE_SOURCE_DIR}/turing/JSONHandler/MachineDescriptions/Transitions.cpp)

target_include_directories(turing PRIVATE
        ${CMAKE_SOURCE_DIR}/turing/SafeStreamWriter
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments
        ${CMAKE_SOURCE_DIR}/turing/JSONHandler
        ${CMAKE_SOURCE_DIR}/turing/JSONHandler/MachineDescriptions)
