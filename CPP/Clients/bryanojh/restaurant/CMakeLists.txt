cmake_minimum_required(VERSION 3.25)
project(restaurant)

set(CMAKE_CXX_STANDARD 17)

add_executable(restaurant Restaurant.cpp Order.cpp Food.cpp BinarySearchTree.cpp BinarySearchTree.h file-manager.cpp file-manager.h Customer.cpp UserManager.cpp UserManager.h User.cpp User.h Admin.cpp Admin.h)
