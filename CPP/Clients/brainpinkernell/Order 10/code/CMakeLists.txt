cmake_minimum_required(VERSION 3.23)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code task1/nodeTest.cpp task1/Node.cpp task1/Node.h)
add_executable(code2 task2/listPlay.cpp task2/Node.cpp task2/Node.h)
