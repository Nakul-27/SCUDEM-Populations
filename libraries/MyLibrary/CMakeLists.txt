# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.4)

# Name of Project
project(MyLibrary)

# Add a library to this build. The name of the library is MyLibrary and it
# consists of only the MyLibrary.cpp file
add_library(MyLibrary src/MyLibrary.cpp)
# target_link_libraries(MyLibrary -lpthread -lutil -ldl)
target_link_libraries(MyLibrary)
