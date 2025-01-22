# CMakeList.txt : CMake project for penguin_2d, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# Define the Penguin2D library
add_library(Penguin2D STATIC
    src/core/penguin_window.cpp
    src/core/penguin_renderer.cpp
    src/core/penguin_text_renderer.cpp
    src/core/penguin_game.cpp
    src/core/penguin_timer.cpp
    src/core/penguin_event_handler.cpp
    src/core/penguin_input.cpp
    src/rendering/penguin_font.cpp
    src/rendering/penguin_text.cpp
    src/rendering/penguin_sprite.cpp
)

# Include directories for the library 
target_include_directories(Penguin2D PUBLIC
    "${PENGUIN_INCLUDE_DIR}/include"
    "${PENGUIN_INCLUDE_DIR}/include/common"
    "${PENGUIN_INCLUDE_DIR}/include/core"
    "${PENGUIN_INCLUDE_DIR}/include/entities"
    "${PENGUIN_INCLUDE_DIR}/include/rendering"
)

# Include private directories for the library
target_include_directories(Penguin2D PRIVATE ${SDL3_TTF_INCLUDE_DIR})

# Link dependencies for the library
target_link_libraries(Penguin2D PRIVATE
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
    SDL3_image::SDL3_image
)
