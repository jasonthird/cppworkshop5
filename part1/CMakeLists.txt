cmake_minimum_required(VERSION 3.10)
project(CalibrationValue)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -fopenmp")

add_library(CalibrationCalculate CalibrationCalculate.cpp)
add_executable(app main.cpp)

target_link_libraries(app CalibrationCalculate)