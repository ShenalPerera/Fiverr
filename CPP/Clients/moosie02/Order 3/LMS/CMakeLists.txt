cmake_minimum_required(VERSION 3.23)
project(LMS)

set(CMAKE_CXX_STANDARD 14)

add_executable(LMS main.cpp Student.cpp Student.h Teacher.cpp Teacher.h Book.cpp Book.h system.cpp system.h)
