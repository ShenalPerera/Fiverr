cmake_minimum_required(VERSION 3.23)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code main.cpp Account.h Transaction.cpp Transaction.h Account.cpp)
