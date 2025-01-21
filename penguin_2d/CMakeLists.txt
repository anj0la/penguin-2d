# CMakeList.txt : CMake project for penguin_2d, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# Add the executable first.
add_executable (penguin_2d "src/penguin_2d.cpp" "src/core/penguin_renderer.cpp")

# Target all include files
target_include_directories(penguin_2d PRIVATE "${PENGUIN_INCLUDE_DIR}")
target_include_directories(penguin_2d PRIVATE "${PENGUIN_INCLUDE_DIR}/common")
target_include_directories(penguin_2d PRIVATE "${PENGUIN_INCLUDE_DIR}/core")
target_include_directories(penguin_2d PRIVATE "${PENGUIN_INCLUDE_DIR}/entities")
target_include_directories(penguin_2d PRIVATE "${PENGUIN_INCLUDE_DIR}/rendering")

target_include_directories(penguin_2d PRIVATE ${SDL3_TTF_INCLUDE_DIR})

# Link to dependices for SDL_image
# target_link_libraries(penguin_2d PRIVATE zlib::zlib)
#target_link_libraries(penguin_2d PRIVATE libpng::libpng)
#target_link_libraries(penguin_2d PRIVATE libjpeg::libjpeg)


# Link to the actual SDL3 library.
target_link_libraries(penguin_2d PRIVATE SDL3::SDL3)
target_link_libraries(penguin_2d PRIVATE SDL3_ttf::SDL3_ttf)
target_link_libraries(penguin_2d PRIVATE SDL3_image::SDL3_image)

# Verify SDL3_ttf include path
#get_target_property(SDL3_TTF_INCLUDE SDL3_ttf::SDL3_ttf INTERFACE_INCLUDE_DIRECTORIES)
#message(STATUS "SDL3_ttf Include: ${SDL3_TTF_INCLUDE}")