cmake_minimum_required(VERSION 3.23)
project(turing)

find_package(Boost REQUIRED)

if (CXX_CHECK)
    set(CMAKE_CXX_CPPCHECK "cppcheck" "--std=c++${CXX_VERSION}" "--enable=warning,style,performance,portability" "--inconclusive")
endif()

add_executable(turing
        ${CMAKE_SOURCE_DIR}/turing/main.cpp
        ${CMAKE_SOURCE_DIR}/turing/SafePrint/SafePrint.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/ParseArguments.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/HelpArgument.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/Handler.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/Reader.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/MachineDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/ValidatorDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/PrintDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/Procuder/ProcudeMachineDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/Procuder/MachineTapeAPI.cpp
        ${CMAKE_SOURCE_DIR}/turing/Procuder/PrintJob.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/ValidateFieilds.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/ParseFields.cpp)

target_include_directories(turing PRIVATE
        ${CMAKE_SOURCE_DIR}/turing/SafePrint
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription
        ${CMAKE_SOURCE_DIR}/turing/Procuder)
