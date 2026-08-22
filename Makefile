TARGET = build/exe
TEST_TARGET = test/build/exe
GCCFLAGS = --std=c23 -Wall -Wextra -fsanitize=address -I/opt/homebrew/Cellar/raylib/6.0/include -L/opt/homebrew/Cellar/raylib/6.0/lib -lraylib
CC = clang
QF = input.txt

SRCS = $(wildcard src/*.c)



.PHONY: all clean build test gui unitest


unitest: unitest_build
	./unit_test/build/unittest

unitest_build: unitest_dir_build
	$(CC) $(GCCFLAGS) src/solve.c unit_test/unit_test.c -o unit_test/build/unittest


unitest_dir_build:
	mkdir -p unit_test/build

all: run

gui: build
	./$(TARGET) --gui

test: build build_test
	./test/build/exe

run: build
	./$(TARGET)

build: $(addprefix build/, $(notdir $(SRCS:.c=.o)))
	$(CC) $^ $(GCCFLAGS) -o $(TARGET)


build/%.o: src/%.c build_dir
	$(CC) -c -o $@ $(GCCFLAGS) $<

build_dir:
	mkdir -p build

clean:
	rm -rf build


build_test: mkdir_build
	$(CC) test/test.c $(GCCFLAGS) -o $(TEST_TARGET)

mkdir_build:
	mkdir -p test/build



