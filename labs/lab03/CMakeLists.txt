cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis212lab03)

set(TEST_RADIX_SORT_SRCS
    testRadixSort.cpp
    LinkedList.h
    ListInterface.h
    Node.h)

add_executable(testradixsort ${TEST_RADIX_SORT_SRCS})
