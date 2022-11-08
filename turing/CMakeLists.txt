cmake_minimum_required(VERSION 3.23)
project(turing)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

add_executable(turing
        ${CMAKE_SOURCE_DIR}/turing/main.cpp
        ${CMAKE_SOURCE_DIR}/turing/SafeStreamWriter/SafeStreamWriter.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/ParseArguments.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/HelpArgument.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/Handler.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/Reader.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidator.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescriptionFields/Alphabet.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescriptionFields/Finals.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescriptionFields/States.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescriptionFields/Transitions.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Name.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Blank.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Initial.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Finals.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Transitions.cpp)

target_include_directories(turing PRIVATE
        ${CMAKE_SOURCE_DIR}/turing/SafeStreamWriter
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments
        ${CMAKE_SOURCE_DIR}/turing/MDHandler)
