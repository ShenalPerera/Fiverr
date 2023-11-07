cmake_minimum_required(VERSION 3.20)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code main.cpp)
add_executable(task4 Task4/read_words.h Task4/read_words.cpp Task4/get_size.h Task4/get_size.cpp Task4/read_words_test.cpp)
add_executable(task5 Task5/part1/all_5_letters.h Task5/part1/all_5_letters.cpp Task5/part1/is_letter.h Task5/part1/five_letter_word.cpp Task5/part1/all_5_letters_test.cpp Task5/part1/is_letter.cpp)
add_executable(task67 Task6/GameCard.h Task6/GameCard.cpp Task6/GameCard-test.cpp)