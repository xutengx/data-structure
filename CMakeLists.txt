cmake_minimum_required(VERSION 3.17)
project(data-structure)

set(CMAKE_CXX_STANDARD 11)

add_executable(data-structure main.cpp 05_array/array.c 05_array/array.h data/LinkedList.hpp data/ArrayStack.hpp data/LinkedListStack.hpp data/ArrayQueue.hpp data/LinkedListQueue.hpp algorithm/Sorts.hpp algorithm/Search.hpp data/SortedSet.hpp data/HashMap.hpp data/BinarySearchTree.hpp data/Heap.hpp data/Graph.hpp)
add_executable(4-median-of-two-sorted-arrays leetcode/editor/cn/4-median-of-two-sorted-arrays.cpp)
add_executable(23-merge-k-sorted-lists leetcode/editor/cn/23-merge-k-sorted-lists.cpp)
add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp)