# CMakeList.txt : CMake project for penguin_2d, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# Add source to this project's executable.
add_executable (penguin_2d "penguin_2d.cpp" "penguin_2d.hpp" "penguin_window.cpp" "penguin_renderer.cpp")

# Use C++ 20 instead of C++ 23 (too new)
set(CMAKE_CXX_STANDARD 20)

# TODO: Add tests and install targets if needed.

# Link to the actual SDL3 library.
# find_package(SDL3)
target_link_libraries(penguin_2d PRIVATE SDL3::SDL3)