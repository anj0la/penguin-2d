# CMakeList.txt : CMake project for penguin_2d, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# Define the Penguin2D library
add_library(Penguin2D SHARED
    src/core/penguin_window.cpp
    src/core/penguin_renderer.cpp
    src/core/penguin_text_renderer.cpp
    src/core/penguin_game_window.cpp
    src/core/penguin_timer.cpp
    src/core/penguin_event_handler.cpp
    src/core/penguin_input.cpp
    src/rendering/penguin_font.cpp
    src/rendering/penguin_text.cpp
    )

# Automatically export all symbols on Windows
if(WIN32)
    set_target_properties(Penguin2D PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# Set the output directories for Penguin2D
set_target_properties(Penguin2D PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/bin"   # DLLs
    LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}/lib"   # Shared Libraries
    ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}/lib"   # Static Libraries
)

# Include directories for the library 
target_include_directories(Penguin2D PUBLIC
    "${PENGUIN_INCLUDE_DIR}/common"
    "${PENGUIN_INCLUDE_DIR}/core"
    "${PENGUIN_INCLUDE_DIR}/rendering"
    "${SDL3_INCLUDE_DIRS}"  # Add SDL3 include directories to PUBLIC
    "${SDL3_TTF_INCLUDE_DIR}" # Add SDL3_ttf include directories to PUBLIC
)

# Copy SDL3 DLLs to bin/ after build
add_custom_command(TARGET Penguin2D POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:SDL3::SDL3>" "${OUTPUT_DIR}/bin/"
    "$<TARGET_FILE:SDL3_ttf::SDL3_ttf>" "${OUTPUT_DIR}/bin/"
)

# Copy all header files into the include directory without subdirectories
file(GLOB_RECURSE HEADER_FILES "${PENGUIN_INCLUDE_DIR}/*.hpp")
add_custom_command(TARGET Penguin2D POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${OUTPUT_DIR}/include"  # Ensure the include directory exists
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${HEADER_FILES} "${OUTPUT_DIR}/include/"
)

# Link dependencies for the library
target_link_libraries(Penguin2D PRIVATE
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
)