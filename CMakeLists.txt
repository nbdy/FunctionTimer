cmake_minimum_required(VERSION 3.0)
project(TimedSection)

set(CMAKE_CXX_STANDARD 11)

add_executable(TimedSection main.cpp FunctionTimer.h)
add_executable(FunctionTimerVerbose main_verbose.cpp FunctionTimer.h)
