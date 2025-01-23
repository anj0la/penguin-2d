cmake_minimum_required (VERSION 3.20)

add_executable(render_shapes
    main.cpp render_shapes.cpp
)

# Link the Penguin2D library
target_link_libraries(render_shapes PRIVATE Penguin2D)
