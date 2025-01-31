cmake_minimum_required (VERSION 3.20)

add_executable(snake
    snake.cpp main.cpp)

# Link the Penguin2D library
target_link_libraries(snake PRIVATE Penguin2D)
