cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 11)

add_executable(task3 Task3/legal_move.h main.cpp Task3/legal_move.cpp)
add_executable(task4 Task4/legal_move.cpp Task4/legal_move.h Task4/get_winner.cpp Task4/get_winner.h Task4/get_winner_test.cpp)
add_executable(task5 Task5/show_multiples.h Task5/show_multiples.cpp Task5/show_multiples_test.cpp)
add_executable(task6 Task6/hide_letters.h Task6/hide_letters.cpp Task6/is_letter.cpp Task6/is_letter.h Task6/hide_letters_test.cpp)