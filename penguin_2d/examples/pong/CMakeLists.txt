cmake_minimum_required (VERSION 3.20)

add_executable(pong
    pong.cpp main.cpp)

# Link the Penguin2D library
target_link_libraries(pong PRIVATE Penguin2D)
