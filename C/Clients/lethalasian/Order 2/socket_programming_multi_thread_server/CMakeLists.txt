cmake_minimum_required(VERSION 3.25)
project(socket_programming_multi_thread_server C)

set(CMAKE_C_STANDARD 11)

add_executable(socket_programming_multi_thread_server multi-tcpserver.c)
add_executable(socket_programming_multi_thread_client tcpclient.c)
