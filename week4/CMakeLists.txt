cmake_minimum_required(VERSION 3.28)
project(week4 C)

set(CMAKE_C_STANDARD 11)

add_executable(week4 main.c
        read_seal_data.c
        avg_weight.c
        checkassignment4.c)
