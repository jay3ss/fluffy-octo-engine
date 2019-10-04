cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis212lab02)

set(SOURCES
    main.cpp
    StackInterface.h
    LinkedStack.h
    Node.h
    PostfixEvaluator.cpp
)

add_executable(main ${SOURCES})
