cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code Network.cpp Network.hpp Post.cpp Post.hpp Account.hpp Account.cpp main.cpp )
