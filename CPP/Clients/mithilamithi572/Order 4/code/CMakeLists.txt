cmake_minimum_required(VERSION 3.23)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code main.cpp Account.cpp Account.hpp Network.cpp Network.hpp LinkedList.cpp LinkedList.hpp Post.cpp Post.hpp General.cpp General.hpp Promotional.cpp Promotional.hpp Poll.cpp Poll.hpp Node.cpp Node.hpp)
add_executable(code1 main.cpp Node.hpp Node.cpp LinkedList.hpp LinkedList.cpp)