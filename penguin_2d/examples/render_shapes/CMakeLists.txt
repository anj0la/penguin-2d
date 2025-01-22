cmake_minimum_required (VERSION 3.20)

add_executable(RenderShapes
    main.cpp
)

# Link the Penguin2D library
target_link_libraries(RenderShapes PRIVATE Penguin2D)

