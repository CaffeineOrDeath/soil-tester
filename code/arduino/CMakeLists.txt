cmake_minimum_required(VERSION 3.12)

file(GLOB SRC_FILES *.c)
add_library(SysArd ${SRC_FILES})
target_compile_options(SysArd PRIVATE "-mmcu=atmega328p")
