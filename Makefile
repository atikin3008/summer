TARGET = build/exe
TEST_TARGET = test/build/exe
GCCFLAGS = --std=c23 -Wall -Wextra -fsanitize=address -I/opt/homebrew/Cellar/raylib/6.0/include -L/opt/homebrew/Cellar/raylib/6.0/lib -lraylib
CC = clang
QF = input.txt

SRCS = $(wildcard src/*.c)



.PHONY: all clean build test gui unit_test

all: run

unit_test: unitest_build
	@./unit_test/build/unit_test

unitest_build: unit_test_dir_build
	@echo Сборка unittest
	@$(CC) $(GCCFLAGS) src/solve.c unit_test/unit_test.c -o unit_test/build/unit_test


unit_test_dir_build:
	@echo Создание папки unit_test/build
	@mkdir -p unit_test/build



gui: build
	@./$(TARGET) --gui

test: build build_test
	@./test/build/exe

run: build
	@./$(TARGET)

build: $(addprefix build/, $(notdir $(SRCS:.c=.o)))
	@echo Cборка исполняемого файлы
	@$(CC) $^ $(GCCFLAGS) -o $(TARGET)


build/%.o: src/%.c build_dir
	@echo Сборка $@
	@$(CC) -c -o $@ $(GCCFLAGS) $<

build_dir:
	@echo Создание папки build
	@mkdir -p build

clean:
	@echo Удаление папок
	@rm -rf build
	@rm -rf test/build
	@rm -rf unit_test/build


build_test: mkdir_build
	@echo Сборка тестов
	@$(CC) test/test.c $(GCCFLAGS) -o $(TEST_TARGET)

mkdir_build:
	@echo Создание папки test/build
	@mkdir -p test/build



