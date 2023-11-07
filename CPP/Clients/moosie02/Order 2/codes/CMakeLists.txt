cmake_minimum_required(VERSION 3.20)
project(codes)

set(CMAKE_CXX_STANDARD 14)

add_executable(p1 P1/main.cpp P1/goldbach_expectation.h P1/goldbach_expectation.cpp P1/binary_search.cpp P1/binary_search.h)
add_executable(p2 P2/main.cpp P2/menu.cpp P2/menu.h)
add_executable(p3 P3/function1.h P3/function1.cpp P3/main.cpp P3/function2.cpp P3/function2.h P3/function3.h P3/function3.cpp)
add_executable(p4 P4/main.cpp P4/linspace.h P4/linspce.cpp P4/sum_of_squares.cpp P4/sum_of_squares.h P4/get_square_error.h P4/get_square_error.cpp)
add_executable(p5 P5/main.cpp P5/is_palindrome.cpp P5/is_palindrome.h P5/reverse.h P5/reverse.cpp)

