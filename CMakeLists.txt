# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.20)

project ("penguin_2d" VERSION 0.0.1)

# Include sub-projects.
add_subdirectory ("penguin_2d")
add_subdirectory ("vendor/SDL3")

