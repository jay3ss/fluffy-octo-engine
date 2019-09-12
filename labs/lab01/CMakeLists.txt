cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis212lab01)

# Create the libraries
add_library(listinterface ListInterface.h)
add_library(rlinked rlinked.h)

# Tell the linker that the libraries are in C++
set_target_properties(
    listinterface
    rlinked
    PROPERTIES LINKER_LANGUAGE CXX
)

# LinkedList depends on ListInterface
target_link_libraries(rlinked listinterface)

# Create the executable for the main program
add_executable(main main.cpp)
target_link_libraries(main rlinked)
