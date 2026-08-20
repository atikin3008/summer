cmake_minimum_required(VERSION 3.30)
project(square_equation_solver C)

set(CMAKE_C_STANDARD 23)

add_executable(square_equation_solver main.c
        types.h
        solve.c
        io.c
        io.h
        solve.h)
