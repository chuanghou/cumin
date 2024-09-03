cmake_minimum_required(VERSION 3.10.2)
project(cumin)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp cumin_util.h)