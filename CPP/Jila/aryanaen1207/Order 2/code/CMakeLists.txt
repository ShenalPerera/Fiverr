cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 11)

add_executable(code1  CSVparser.cpp CSVparser.hpp HashTable.cpp)
