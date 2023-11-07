cmake_minimum_required(VERSION 3.23)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code main.cpp bishop.cpp chessBoard.cpp game.cpp king.cpp knight.cpp pawn.cpp piece.cpp player.cpp queen.cpp blockedKing.cpp rook.cpp location.cpp
        bishop.h chessBoard.h game.h king.h knight.h pawn.h piece.h player.h queen.h blockedKing.h rook.h location.h)
