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
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/Handler.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/Reader.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/ValidatorDescription.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescriptionFields/Alphabet.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescriptionFields/Finals.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescriptionFields/States.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MachineDescriptionFields/Transitions.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Name.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Blank.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Initial.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Finals.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/MDValidatorFields/Transitions.cpp
        ${CMAKE_SOURCE_DIR}/turing/MDHandler/PrintDescription.cpp)

target_include_directories(unit_tests PRIVATE
        ${CMAKE_SOURCE_DIR}/turing/ParseArguments
        ${CMAKE_SOURCE_DIR}/turing/SafePrint
        ${CMAKE_SOURCE_DIR}/turing/MDHandler)

target_link_libraries(unit_tests gtest gtest_main)
