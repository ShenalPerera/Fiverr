cmake_minimum_required(VERSION 3.20)
project(part_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(part_2
        CoffeMaker.cpp Clock.cpp Menu.h Menu.cpp)
