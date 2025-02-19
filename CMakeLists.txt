# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.20)

# Define the project, version and languages support
project(Penguin2D VERSION 0.1.0 LANGUAGES CXX)

# Use C++ 20
set(CMAKE_CXX_STANDARD 20)

# Set the root output directory for build artifacts
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/penguin_2d")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/bin")  # For DLLs and EXEs
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}/lib")  # For shared libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}/lib")  # For static libraries

# Define variables for ease to access include directories
set(PENGUIN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/penguin_2d/include")
set(SDL3_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/external/SDL3/include/SDL3")
set(SDL3_TTF_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/SDL3_ttf/include/SDL3_ttf")

# Include sub-directories needed for Penguin2D to work
add_subdirectory ("penguin_2d")
add_subdirectory ("external/SDL3")
add_subdirectory ("external/SDL3_ttf")
