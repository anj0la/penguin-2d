# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.20)

# Define the project, version and languages support
project(Penguin2D VERSION 0.1.0 LANGUAGES CXX)

# Use C++ 20
set(CMAKE_CXX_STANDARD 20)

# Define variables for ease to access include directorie
set(PENGUIN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/penguin_2d/include")
set(SDL3_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/external/SDL3/include")
set(SDL3_TTF_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/SDL3_ttf/include")
set(SDL3_IMAGE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/SDL3_image/include")

# Include sub-directories needed for Penguin2D to work
add_subdirectory ("penguin_2d")
add_subdirectory ("external/SDL3")
add_subdirectory ("external/SDL3_ttf")
add_subdirectory ("external/SDL3_image")