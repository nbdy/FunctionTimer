cmake_minimum_required(VERSION 3.0)
project(FunctionTimer)

option(EXAMPLE "Build the example" ON)

set(CMAKE_CXX_STANDARD 11)

add_library(FunctionTimer FunctionTimer.h)
set_target_properties(FunctionTimer PROPERTIES LINKER_LANGUAGE CXX)

if(EXAMPLE)
    add_executable(example example.cpp FunctionTimer.h)

endif()
