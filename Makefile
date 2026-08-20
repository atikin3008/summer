TARGET = build/exe
GCCFLAGS = --std=c23 -Wall -Wextra -fsanitize=address
CC = GCC

SRCS = $(wildcard src/*.c)



.PHONY: all clean build

all: run

run: build
	./$(TARGET)

build: build_dir $(SRCS)
	$(CC) $(wildcard build/*.o) $(GCCFLAGS) -o $(TARGET)


src/%.c:
	$(CC) -c -o build/$*.o $(GCCFLAGS) $@


build_dir:
	mkdir -p build

clean:
	rm -rf build/*





