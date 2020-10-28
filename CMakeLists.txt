# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(Project)

# Create a few variables for the folder names, so they are easier to rename in
# the future
set(MODELS_DIR src/models)

# Add all the source files needed to build the executable
add_executable(
  Project
  src/main.cpp
  ${MODELS_DIR}/Immigrant.cpp
)

# Include the directory where MyLibrary project is. Otherwise, we can't use the
# library
add_subdirectory(libraries/MyLibrary)

# Link the executable and the library together
target_link_libraries(Project MyLibrary)
