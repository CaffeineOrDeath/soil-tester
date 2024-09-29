cmake_minimum_required(VERSION 3.12)

file(GLOB SRC_FILES *.c)
add_library(Sampler ${SRC_FILES})
