cmake_minimum_required(VERSION 3.23)
project(Clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(Clion main.cpp Location.cpp Location.hpp Item.cpp Item.hpp Player.cpp Player.hpp main.hpp Monster.cpp Monster.hpp Dragon.cpp Dragon.hpp)
