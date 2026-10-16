cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(chip8_emu)

# putting in  17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g")

include(CMakePrintHelpers)


add_library(CHIP8 src/CHIP8.cpp include/CHIP8.h)
target_include_directories(CHIP8
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(main src/main.cpp include/CHIP8.h)