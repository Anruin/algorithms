cmake_minimum_required(VERSION 3.26)
project(untitled C)

set(CMAKE_C_STANDARD 23)

include_directories(helper)

add_executable(insertion-sort insertion-sort/main.c)
add_executable(sum-array sum-array/main.c)
add_executable(insertion-sort-decreasing insertion-sort-decreasing/main.c)
add_executable(linear-search linear-search/main.c)