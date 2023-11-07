cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(p3 P3/get_user_answer.h P3/get_user_answer.cpp P3/testing.cpp P3/put_in_order.h P3/put_in_order.cpp
                P3/min_and_max.h P3/min_and_max.cpp)

add_executable(p4 P4/hw5-prob4.cpp)

add_executable(p5 P5/hw5-cards.cpp P5/GameCard.cpp P5/GameCard.h)
