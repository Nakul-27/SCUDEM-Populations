# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.8)

project(Project VERSION 0.0.0 LANGUAGES CXX)

find_package(gsl REQUIRED)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set(GCC_COVERAGE_COMPILE_FLAGS "-Wc++11-extensions")

# Name of the project

set(CMAKE_CXX_STANDARD 14)

# Create a few variables for the folder names, so they are easier to rename in
# the future
set(MODELS_DIR src/models)
set(GENERATOR_DIR src/generators)

# Add all the source files needed to build the executable
add_executable(
  Project
  src/main.cpp
  ${MODELS_DIR}/person.cpp
  ${GENERATOR_DIR}PersonGenerator.cpp
  ${GSL_INCLUDE_DIR}
)

target_include_directories(Project PRIVATE ${GSL_INCLUDE_DIR})
target_link_directories(Project PRIVATE ${GSL_INCLUDE_DIR})
target_link_libraries(Project PRIVATE ${GSL_LIBRARIES})
