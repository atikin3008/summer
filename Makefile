TARGET = build/exe
SRC = build/main.o build/io.o build/solve.o

.PHONY: all clean

build/main.o: src/main.c
	gcc -c --std=c23 -Wall -Wextra -fsanitize=address -o build/main.o src/main.c

build/io.o: src/io.c
	gcc -c --std=c23 -Wall -Wextra -fsanitize=address -o build/io.o src/io.c

build/solve.o: src/solve.c
	gcc -c --std=c23 -Wall -Wextra -fsanitize=address -o build/solve.o src/solve.c

$(TARGET) : $(SRC)
	gcc --std=c23 -Wall -Wextra -fsanitize=address -o $(TARGET) $(SRC)

all: $(TARGET)
	$(TARGET)

clean:
	rm -rf build/*




