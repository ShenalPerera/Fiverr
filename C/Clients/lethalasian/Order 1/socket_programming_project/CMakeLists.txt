cmake_minimum_required(VERSION 3.25)
project(socket_programming_project C)

set(CMAKE_C_STANDARD 11)

add_executable(socket_programming_client tcpclient.c)
add_executable(socket_programming_server tcpserver.c)
