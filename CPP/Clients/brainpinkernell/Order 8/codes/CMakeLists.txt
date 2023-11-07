cmake_minimum_required(VERSION 3.23)
project(codes)

set(CMAKE_CXX_STANDARD 14)

add_executable(codes main.cpp)
add_executable(p9.2 p9.2/linked-list-functs.h p9.2/linked-list-functs.cpp p9.2/Node.cpp p9.2/Node.h p9.2/linked-list-tests.cpp)
add_executable(p8.1.3 p8.1.3/linked-list-functs.h p8.1.3/linked-list-functs.cpp p8.1.3/Node.cpp p8.1.3/Node.h p8.1.3/words-vector.cpp)

add_executable(p8.2.4n5 p8.2.4n5/linked-list-functs.h p8.2.4n5/linked-list-functs.cpp p8.2.4n5/Node.cpp p8.2.4n5/Node.h p8.2.4n5/linked-list-tests.cpp)

add_executable(p9.3 p9.3/linked-list-functs.h p9.3/linked-list-functs.cpp p9.3/Node.h p9.3/Node.cpp p9.3/linked-list-tests.cpp)
add_executable(p9.4 p9.4/GameCard.h p9.4/GameCard.cpp p9.4/GameCard-test.cpp)
add_executable(p9.5 p9.5/GameCard.cpp p9.5/GameCard.h p9.5/NewGameCard.cpp p9.5/NewGameCard.h p9.5/derived-play.cpp)