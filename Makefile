TARGET = build/exe
GCCFLAGS = --std=c23 -Wall -Wextra -fsanitize=address
CC = GCC

SRCS = $(wildcard src/*.c)



.PHONY: all clean build

all: run

run: build
	./$(TARGET)

build: $(addprefix build/, $(notdir $(SRCS:.c=.o)))
	$(CC) $^ $(GCCFLAGS) -o $(TARGET)


build/%.o: src/%.c build_dir
	$(CC) -c -o $@ $(GCCFLAGS) $<

build_dir:
	mkdir -p build

clean:
	rm -rf build/*




