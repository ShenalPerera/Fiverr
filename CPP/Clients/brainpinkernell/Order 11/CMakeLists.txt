cmake_minimum_required(VERSION 3.23)
project(Order_11)

set(CMAKE_CXX_STANDARD 14)


add_executable(task1 Task1/addCommas.cpp  Task1/addCommas.h)
add_executable(task2 Task2/gcd.h Task2/gcd.cpp)
add_executable(task3 Task3/DoublyLinkedList.cpp Task3/DoublyLinkedList.h Task3/main.cpp)