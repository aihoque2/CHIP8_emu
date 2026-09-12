cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(chip8_emu)

add_library(CHIP8 CHIP8.h CHIP8.cpp)
add_dependencies()

add_executable(main main.cpp CHIP8.h)
s