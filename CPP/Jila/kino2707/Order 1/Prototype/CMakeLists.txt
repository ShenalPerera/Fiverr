cmake_minimum_required(VERSION 3.20)
project(Prototype)

set(CMAKE_CXX_STANDARD 14)

add_executable(Prototype main.cpp Player.cpp Monster.cpp Location.cpp item.cpp dragon.cpp)
