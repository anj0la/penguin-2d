# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.20)

# Use C++ 20 instead of C++ 23 (too new)
set(CMAKE_CXX_STANDARD 20)

# Define a variable for the include directory.
set(PENGUIN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/penguin_2d/include")
set(SDL3_TTF_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/vendor/SDL3_ttf/include")

# Ensure directories for assets exist
set(FONT_DIR "${CMAKE_SOURCE_DIR}/penguin_2d/fonts")
set(ASSETS_DIR "${CMAKE_CURRENT_BINARY_DIR}/penguin_2d/assets")

file(MAKE_DIRECTORY ${FONT_DIR})
file(MAKE_DIRECTORY ${ASSETS_DIR})

# Define project.
project ("penguin_2d" VERSION 0.0.1)

# Include sub-projects.
add_subdirectory ("penguin_2d")
add_subdirectory ("vendor/SDL3")
add_subdirectory ("vendor/SDL3_ttf")
add_subdirectory ("vendor/SDL3_image")