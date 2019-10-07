cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis212lab02)

# Main program executables
set(FULL_SOURCES
    main.cpp
    FileReader.cpp
    LinkedStack.h
    Node.h
    PostfixEvaluator.cpp
    StackInterface.h
)

add_executable(main ${FULL_SOURCES})

# Test executables
# Test the file reader
set(TEST_FILE_READER_SRCS
    testFileReader.cpp
    FileReader.cpp
)

add_executable(testfilereader ${TEST_FILE_READER_SRCS})

# Test the postfix evaluator
set(TEST_POSTFIX_EVALUATOR_SRCS
    testPostfixEvaluator.cpp
    LinkedStack.h
    Node.h
    PostfixEvaluator.cpp
    StackInterface.h
)

add_executable(testpostfixevaluator ${TEST_POSTFIX_EVALUATOR_SRCS})
