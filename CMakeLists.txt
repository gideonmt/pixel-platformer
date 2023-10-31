cmake_minimum_required(VERSION 3.5.1)
project(PixelPlatformer VERSION 1.0
                     DESCRIPTION "A simple 2D platformer game in C."
                     LANGUAGES C)

# Add SDL2 CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Set output path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_net REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(BIN_NAME pixel-platformer)

# Create separate source and header directories
file(GLOB SRC src/*.c)
file(GLOB HDR src/*.h)

add_executable(${BIN_NAME} ${SRC} ${HDR})

# Set include directories
target_include_directories(${BIN_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${BIN_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})

# Link libraries individually
target_link_libraries(${BIN_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${BIN_NAME} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(${BIN_NAME} ${SDL2_MIXER_LIBRARIES})
target_link_libraries(${BIN_NAME} ${SDL2_NET_LIBRARIES})
target_link_libraries(${BIN_NAME} ${SDL2_TTF_LIBRARIES})

# Copy resources to the output directory
file(COPY res DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
