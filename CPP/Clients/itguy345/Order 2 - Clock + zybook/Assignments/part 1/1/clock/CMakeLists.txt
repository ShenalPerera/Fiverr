cmake_minimum_required(VERSION 3.20)
project(clock)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(clock1 chadaClock.cpp
        Clock.cpp Clock.h Clock12.cpp Clock12.h )
