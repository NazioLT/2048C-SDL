cmake_minimum_required(VERSION 3.29)
project(2048_App C)

set(CMAKE_C_STANDARD 17)

# Create an option to switch between a system sdl library and a vendored sdl library
option(2048C_VENDORED "Use vendored libraries" OFF)

if(2048C_VENDORED)
    add_subdirectory(vendored/sdl EXCLUDE_FROM_ALL)
    add_subdirectory(vendored/sdl_image EXCLUDE_FROM_ALL)
else()
    find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
    find_package(SDL2_image REQUIRED)
endif()

# -------------------------------
#         CHECK LIBRARIES
# -------------------------------

if(NOT SDL2_FOUND)
    message("SDL2 library is not found!")
endif()

if(NOT SDL2_image_FOUND)
    message("SDL2_image library is not found!")
endif()

# -------------------------------
#         Create Project
# -------------------------------

# Create your game executable target as usual
add_executable(2048_App "src/main.c")

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(2048_App PRIVATE SDL2::SDL2main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(2048_App PRIVATE SDL2::SDL2)
target_link_libraries(2048_App PRIVATE SDL2_image::SDL2_image)