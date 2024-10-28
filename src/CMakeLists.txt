cmake_minimum_required(VERSION 3.10)
project(my_game)

# Find the SDL2, SDL2_image, and SDL2_mixer packages
find_package(SDL2 REQUIRED COMPONENTS SDL2)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Add your source files
set(SOURCES main.cpp Game.cpp State.cpp Sprite.cpp) # You can add more source files here if needed

# Create the executable
add_executable(my_game ${SOURCES})

# Link SDL2, SDL2_image, and SDL2_mixer to the executable
target_link_libraries(my_game PRIVATE SDL2::SDL2 SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer)

# Set the output directories for the compiled executable
set_target_properties(my_game PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
