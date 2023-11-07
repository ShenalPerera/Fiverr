cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(task3 task3/Point.cpp task3/Point.h task3/points-play.cpp)
add_executable(task4 task4/cards-play.cpp task4/GameCard.h task4/GameCard.cpp)
