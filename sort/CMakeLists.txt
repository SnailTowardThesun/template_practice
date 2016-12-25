cmake_minimum_required(VERSION 2.6)

Project(sort)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SRC_FILE_LISTS ${SRC_DIR}/sort.cpp src/CStackSort.cpp src/CStackSort.h)

# src part
include_directories(${SRC_DIR})
aux_source_directory(${SRC_DIR} SRC_FILE_LISTS)

add_executable(sort ${SRC_FILE_LISTS})
