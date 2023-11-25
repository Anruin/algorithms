cmake_minimum_required(VERSION 3.26)
project(untitled C)

set(CMAKE_C_STANDARD 23)

include_directories(helper)

add_executable(insertion-sort insertion-sort/main.c)
add_executable(sum-array sum-array/main.c)
add_executable(insertion-sort-descending insertion-sort-descending/main.c)
add_executable(linear-search linear-search/main.c)
add_executable(add-binary-integers add-binary-integers/main.c)
add_executable(selection-sort selection-sort/main.c)
add_executable(merge-sort merge-sort/main.c)