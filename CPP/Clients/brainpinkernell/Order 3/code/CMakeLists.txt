cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 11)

add_executable(code five_letter_str.h five_letter_str.cpp five_letter_str_test.cpp)
