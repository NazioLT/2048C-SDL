cmake_minimum_required(VERSION 3.29)
project(2048_App C)

set(CMAKE_C_STANDARD 17)

# -------------------------------
#         GET LIBRARIES
# -------------------------------

option(2048C_VENDORED "Use vendored libraries" OFF)

if(2048C_VENDORED)
    add_subdirectory(vendored/sdl EXCLUDE_FROM_ALL)
    add_subdirectory(vendored/sdl_image EXCLUDE_FROM_ALL)
else()
    find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
    
    find_package(SDL2_image)
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

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/build)

set(APP2048_SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(APP2048_RESOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/resources)
set(APP2048_CMAKE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

file(GLOB_RECURSE C_FILES ${APP2048_SRC_PATH}/*.c)
file(GLOB_RECURSE H_FILES ${APP2048_SRC_PATH}/*.h)
file(GLOB_RECURSE RESOURCES_FILES ${APP2048_RESOURCES_PATH}/*)

add_executable(2048_App "src/main.c" ${C_FILES} ${H_FILES})

include_directories(${APP2048_SRC_PATH})
target_link_libraries(2048_App PRIVATE SDL2_image::SDL2_image)

if(TARGET SDL2::SDL2main)
    target_link_libraries(2048_App PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(2048_App PRIVATE SDL2::SDL2)

# Copying Libraries
add_custom_command(TARGET 2048_App POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${SDL2_image_DIR}/../bin/SDL2_image.dll" "${EXECUTABLE_OUTPUT_PATH}/$<CONFIG>/")

add_custom_command(TARGET 2048_App POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${SDL2_DIR}/../bin/SDL2.dll" "${EXECUTABLE_OUTPUT_PATH}/$<CONFIG>/")

# Copying Resources
# Degueu pour l'instant, a opti plus tard...
add_custom_command(TARGET 2048_App PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "${EXECUTABLE_OUTPUT_PATH}/$<CONFIG>/resources/")
add_custom_command(TARGET 2048_App PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "${APP2048_CMAKE_PATH}/resources/")

add_custom_command(TARGET 2048_App POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${RESOURCES_FILES}" "${EXECUTABLE_OUTPUT_PATH}/$<CONFIG>/resources/"
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${RESOURCES_FILES}" "${APP2048_CMAKE_PATH}/resources/")