cmake_minimum_required(VERSION 3.20)
project(Code)

set(CMAKE_CXX_STANDARD 14)

add_executable(task5 Task5/get_size.cpp Task5/get_size.h Task5/get_size_test.cpp)
add_executable(task6 Task6/add_to_file.h Task6/add_to_file.cpp Task6/add_to_file_test.cpp)
add_executable(task7 Task7/letter_elsewhere.cpp Task7/letter_elsewhere.h Task7/letter_match.cpp Task7/letter_match.h Task7/rand_int.cpp Task7/guess_word_from_file.cpp Task7/rand_int.h Task7/guess_match.cpp Task7/guess_match.h Task7/get_size.cpp Task7/get_size.h Task7/add_to_file.h Task7/add_to_file.cpp)