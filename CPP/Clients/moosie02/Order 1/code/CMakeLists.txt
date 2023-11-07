cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code main.cpp)
add_executable(P1 P1/main.cpp)
add_executable(P2 P2/calculate_area.cpp P2/calculate_area.hpp P2/main.cpp P2/is_square.cpp P2/is_square.hpp)
add_executable(P3 P3/calculate_area.hpp P3/calculate_area.cpp P3/main.cpp P3/is_square.cpp P3/is_square.hpp)
add_executable(P4 P4/calculate_area.cpp P4/calculate_area.hpp P4/main.cpp P2/is_square.hpp P4/is_square.cpp)
add_executable(P5 P5/get_fibonacci_value.cpp P5/get_fibonacci_value.hpp P5/main.cpp)
add_executable(P6 P6/main.cpp P6/getSumOfDigits.cpp P6/getSumOfDigits.hpp P6/isHappy.cpp P6/isHappy.hpp)
