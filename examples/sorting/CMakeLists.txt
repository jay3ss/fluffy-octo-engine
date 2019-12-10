cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis212sortingexamples)

set(SELECTION_SORT_SRCS
    testSelectionSort.cpp
    selectionsort.h)

add_executable(testselectionsort ${SELECTION_SORT_SRCS})

set(BUBBLE_SORT_SRCS
    testBubbleSort.cpp
    bubblesort.h)

add_executable(testbubblesort ${BUBBLE_SORT_SRCS})

set(INSERTION_SORT_SRCS
    testInsertionSort.cpp
    insertionsort.h)

add_executable(testselectionsort ${INSERTION_SORT_SRCS})
