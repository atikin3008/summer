cmake_minimum_required(VERSION 3.29.3)

project(square_equation_solver C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(square_equation_solver main.c)

target_compile_options(square_equation_solver PRIVATE
        -D_DEBUG
        -ggdb3

        -Wall
        -Wextra
        -Wmissing-declarations
        -Wcast-align
        -Wcast-qual
        -Wchar-subscripts
        -Wconversion
        -Wempty-body
        -Wfloat-equal
        -Wformat-nonliteral
        -Wformat-security
        -Wformat-signedness
        -Wformat=2
        -Winline
        -Wpacked
        -Wpointer-arith
        -Winit-self
        -Wredundant-decls
        -Wshadow
        -Wsign-conversion
        -Wstrict-overflow=2
        -Wswitch-default
        -Wswitch-enum
        -Wundef
        -Wunreachable-code
        -Wunused
        -Wvariadic-macros

        -Wno-missing-field-initializers
        -Wno-narrowing
        -Wno-varargs

        -Wstack-protector
        -fcheck-new
        -fsized-deallocation
        -fstack-protector
        -fstrict-overflow
        -fno-omit-frame-pointer
        -Wlarger-than=8192
        -fPIE

        -Werror=vla

        -fsanitize=address
        -fsanitize=alignment
        -fsanitize=bool
        -fsanitize=bounds
        -fsanitize=enum
        -fsanitize=float-cast-overflow
        -fsanitize=float-divide-by-zero
        -fsanitize=integer-divide-by-zero
        -fsanitize=nonnull-attribute
        -fsanitize=null
        -fsanitize=return
        -fsanitize=returns-nonnull-attribute
        -fsanitize=shift
        -fsanitize=signed-integer-overflow
        -fsanitize=undefined
        -fsanitize=unreachable
        -fsanitize=vla-bound
        -fsanitize=vptr
)

target_link_options(square_equation_solver PRIVATE
        -fsanitize=address
        -fsanitize=alignment
        -fsanitize=bool
        -fsanitize=bounds
        -fsanitize=enum
        -fsanitize=float-cast-overflow
        -fsanitize=float-divide-by-zero
        -fsanitize=integer-divide-by-zero
        -fsanitize=nonnull-attribute
        -fsanitize=null
        -fsanitize=return
        -fsanitize=returns-nonnull-attribute
        -fsanitize=shift
        -fsanitize=signed-integer-overflow
        -fsanitize=undefined
        -fsanitize=unreachable
        -fsanitize=vla-bound
        -fsanitize=vptr
)