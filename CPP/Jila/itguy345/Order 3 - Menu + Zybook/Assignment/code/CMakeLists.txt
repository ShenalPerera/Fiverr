cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code main.cpp Bank.cpp Bank.h InvestData.cpp InvestData.h)
