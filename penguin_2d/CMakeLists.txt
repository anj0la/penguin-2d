﻿# CMakeList.txt : CMake project for penguin_2d, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# Add the executable first.
add_executable (penguin_2d "src/penguin_2d.cpp" "src/penguin_2d.cpp" "src/penguin_window.cpp" "src/penguin_renderer.cpp" "src/penguin_event_handler.cpp" "src/penguin_input.cpp")

# TODO: Add tests and install targets if needed.
target_include_directories(penguin_2d PRIVATE ${PENGUIN_INCLUDE_DIR})

# Link to the actual SDL3 library.
target_link_libraries(penguin_2d PRIVATE SDL3::SDL3)
target_link_libraries(penguin_2d PRIVATE SDL3_ttf::SDL3_ttf)
