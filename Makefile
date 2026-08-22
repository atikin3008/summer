TARGET = build/exe
TEST_TARGET = test/build/exe
GCCFLAGS = --std=c23 -Wall -Wextra -fsanitize=address -I/opt/homebrew/Cellar/raylib/6.0/include -L/opt/homebrew/Cellar/raylib/6.0/lib -lraylib
CC = clang
QF = input.txt

SRCS = $(wildcard src/*.c)



.PHONY: all clean build test gui


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



