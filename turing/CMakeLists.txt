cmake_minimum_required(VERSION 3.23)
project(turing)

set(CXX_VERSION 20)

set(CMAKE_CXX_STANDARD ${CXX_VERSION})

find_package(Boost REQUIRED)

set(CMAKE_CXX_CPPCHECK "cppcheck" "--std=c++${CXX_VERSION}" "--enable=warning,style,performance,portability")

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
