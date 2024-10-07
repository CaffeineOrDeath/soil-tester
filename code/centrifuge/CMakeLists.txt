cmake_minimum_required(VERSION 3.12)

file(GLOB SRC_FILES *.c)
add_library(Centrifuge ${SRC_FILES})
target_include_directories(Centrifuge PUBLIC include/)

