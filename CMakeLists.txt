cmake_minimum_required(VERSION 3.17)
project(data-structure)

set(CMAKE_CXX_STANDARD 11)

add_executable(data-structure main.cpp 05_array/array.c 05_array/array.h data/LinkedList.hpp data/ArrayStack.hpp data/LinkedListStack.hpp)