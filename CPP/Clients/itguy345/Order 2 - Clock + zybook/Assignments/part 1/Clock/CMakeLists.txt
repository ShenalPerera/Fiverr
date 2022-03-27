cmake_minimum_required(VERSION 3.20)
project(Clock)

set(CMAKE_CXX_STANDARD 14)

add_executable(Clock
        ChadaClocks.h ChadaClocks.cpp Menu.cpp Menu.h main.cpp)
