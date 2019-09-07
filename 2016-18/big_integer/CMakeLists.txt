cmake_minimum_required(VERSION 3.10)
project(big_integer)

set(CMAKE_CXX_STANDARD 11)

add_executable(big_integer main.cpp big_integer.cpp big_integer.h)