cmake_minimum_required(VERSION 2.6)

Project(tmplate_practice)

set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall")

# objs
set (RS_SERVER_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/objs/)
set (EXECUTABLE_OUTPUT_PATH ${RS_SERVER_BINARY_DIR})
set (LIBRARY_OUTPUT_PATH ${RS_SERVER_BINARY_DIR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sort)
