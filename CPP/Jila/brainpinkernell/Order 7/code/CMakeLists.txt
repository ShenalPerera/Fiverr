cmake_minimum_required(VERSION 3.23)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code pack-play.cpp CardPack.cpp CardPack.h GameCard.h GameCard.cpp)
