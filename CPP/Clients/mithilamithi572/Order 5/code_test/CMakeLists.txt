cmake_minimum_required(VERSION 3.23)
project(code_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(code_test main.cpp LinkedList.cpp LinkedList.hpp Node.hpp Node.cpp)
