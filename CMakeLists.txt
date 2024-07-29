cmake_minimum_required(VERSION 3.5.0)
project(Moving_Median_Filter VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Moving_Median_Filter main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
