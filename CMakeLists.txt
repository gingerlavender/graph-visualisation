cmake_minimum_required(VERSION 3.16)

project(oop_lab1)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_EXE main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -fsanitize=address,undefined")

add_library(graph_dialog lib/graph_dialog.h lib/graph_dialog.cpp)

add_library(input lib/input.h lib/input.cpp)

add_library(graphlib lib/graph.h lib/graph.cpp)

link_libraries(graph_dialog input graphlib)

add_executable(main ${SOURCE_EXE})
