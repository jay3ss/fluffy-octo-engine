cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis212lab02)

# Create the libraries
add_library(stackinterface StackInterface.h)
add_library(linkedstack LinkedStack.h)
add_library(node Node.h)

# Tell the linker that the libraries are C++
set_target_properties(
    stackinterface
    linkedstack
    node
    PROPERTIES LINKER_LANGUAGE CXX
)

#
target_link_libraries(linkedstack stackinterface node)


# Create the executables for
add_executable(main main.cpp)
target_link_libraries(main linkedstack)
