cmake_minimum_required(VERSION 3.23)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task.10.3 "Task 10.3/exc-play.cpp" "Task 10.5/CardPile.cpp" "Task 10.5/CardPile.h")
add_executable(Task.10.4 "Task 10.4/GameCard.h" "Task 10.4/GameCard.cpp" "Task 10.4/Node.h" "Task 10.4/Node.cpp" "Task 10.4/node-test.cpp")
add_executable(Task.10.5 "Task 10.5/GameCard.h" "Task 10.5/GameCard.cpp" "Task 10.5/Node.h" "Task 10.5/Node.cpp" "Task 10.5/linked-list-functs.cpp" "Task 10.5/linked-list-functs.h" "Task 10.5/pile-play.cpp")
add_executable(Task.11.2  "Task 11.2/GameCard.cpp" "Task 11.2/GameCard.h" "Task 11.2/NewGameCard.cpp" "Task 11.2/NewGameCard.h" "Task 11.2/dynamic-cards.cpp")
add_executable(Task.11.3 "Task 11.3/Rankable.h" "Task 11.3/GameCard.h" "Task 11.3/GameCard.cpp" "Task 11.3/dynamic-cards.cpp" "Task 11.3/NewGameCard.h" "Task 11.3/NewGameCard.cpp")
add_executable(Task.11.5 "Task 11.5/GameCard.h" "Task 11.5/GameCard.cpp" "Task 11.5/game.cpp" "Task 11.5/Rankable.h" "Task 11.5/rand_int.h" "Task 11.5/rand_int.cpp")