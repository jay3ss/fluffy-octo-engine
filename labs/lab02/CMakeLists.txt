cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis212lab02)

set(FULL_SOURCES
    main.cpp
    FileReader.cpp
    LinkedStack.h
    Node.h
    PostfixEvaluator.cpp
    StackInterface.h
)

add_executable(main ${FULL_SOURCES})
