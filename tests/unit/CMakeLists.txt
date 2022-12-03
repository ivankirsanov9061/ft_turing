cmake_minimum_required(VERSION 3.23)
project(unit_tests)

enable_testing()
find_package(GTest REQUIRED)

add_executable(unit_tests
        ${CMAKE_SOURCE_DIR}/tests/unit/ParseArguments.cpp
        ${CMAKE_SOURCE_DIR}/tests/unit/MachineDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/ParseArguments.cpp
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments/HelpArgument.cpp
        ${CMAKE_SOURCE_DIR}/turing/SafePrint/SafePrint.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/Handler.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/Reader.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/MachineDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/ValidatorDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/PrintDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/ValidateFieilds.cpp
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription/ParseFields.cpp)

target_include_directories(unit_tests PRIVATE
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments
        ${CMAKE_SOURCE_DIR}/turing/SafePrint
        ${CMAKE_SOURCE_DIR}/turing/MachineDescription)

target_link_libraries(unit_tests gtest gtest_main)
