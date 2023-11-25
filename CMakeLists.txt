cmake_minimum_required(VERSION 3.26)
project(algorithms C)

set(CMAKE_C_STANDARD 23)

include_directories(helper)

# Sum array
add_executable(sum-array sum-array/main.c)

# Insertion sort
add_executable(insertion-sort insertion-sort/main.c)

# Insertion sort descending
add_executable(insertion-sort-descending insertion-sort-descending/main.c)

# Linear search
add_executable(linear-search linear-search/main.c)

# Add binary integers
add_executable(add-binary-integers add-binary-integers/main.c
        merge-sort/main.c)

# Selection sort
add_executable(selection-sort selection-sort/main.c)

# Merge sort
add_executable(merge-sort merge-sort/main.c)

# Experimental: Insertion sort with SDL
add_executable(insertion-sort-sdl insertion-sort-sdl/main.c)
target_include_directories(insertion-sort-sdl PUBLIC helper)
target_include_directories(insertion-sort-sdl PUBLIC SDL/include SDL_ttf/include)
target_link_libraries(insertion-sort-sdl SDL3 SDL3_ttf)
target_link_directories(insertion-sort-sdl PUBLIC SDL/cmake-build-debug SDL_ttf/cmake-build-debug)
