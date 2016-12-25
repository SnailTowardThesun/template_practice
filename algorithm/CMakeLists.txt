cmake_minimum_required(VERSION 2.6)

Project(algorithm)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SRC_FILE_LISTS ${SRC_DIR}/algorithm.cpp)

# src part
include_directories(${SRC_DIR})
aux_source_directory(${SRC_DIR} SRC_FILE_LISTS)

add_executable(algorithm ${SRC_FILE_LISTS})
