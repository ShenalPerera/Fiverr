cmake_minimum_required(VERSION 3.25)
project(async_server C)

set(CMAKE_C_STANDARD 11)

add_executable(tcpsever tcpclient.c)
add_executable(async_server async-tcpserver.c)