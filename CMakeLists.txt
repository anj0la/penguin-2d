# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.20)

# Use C++ 20 instead of C++ 23 (too new)
set(CMAKE_CXX_STANDARD 20)

# Define a variable for the include directory.
set(PENGUIN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/penguin_2d/include")
set(SDL3_TTF_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/SDL3_ttf/include")

# Define project.
project ("penguin_2d" VERSION 0.0.1)

# Include sub-projects.
add_subdirectory ("penguin_2d")
add_subdirectory ("external/SDL3")
add_subdirectory ("external/SDL3_ttf")
add_subdirectory ("external/SDL3_image")