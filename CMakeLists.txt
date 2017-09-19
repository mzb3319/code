Cmake_minimum_required(VERSION 3.6)
project(code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp)
add_executable(code ${SOURCE_FILES})