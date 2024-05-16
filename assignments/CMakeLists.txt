cmake_minimum_required(VERSION 3.28)
project(week3p2 C)

set(CMAKE_C_STANDARD 11)

add_executable(week3p2 main.c
        sortedlist.c
        sortedlist_array.c
)
