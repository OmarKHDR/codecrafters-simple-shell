cmake_minimum_required(VERSION 3.13)

project(codecrafters-shell)
# Enable debug symbols
set(CMAKE_BUILD_TYPE Debug)

# Add debug flags
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -Wall")

file(GLOB_RECURSE SOURCE_FILES src/*.c src/*.h)

set(CMAKE_C_STANDARD 23) # Enable the C23 standard

add_executable(shell ${SOURCE_FILES})
