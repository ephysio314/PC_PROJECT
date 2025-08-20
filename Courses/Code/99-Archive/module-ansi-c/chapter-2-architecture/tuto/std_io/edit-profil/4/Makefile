
CC= gcc -std=c89

P1= src/
OBJ= $(P1)convert.o

.PHONY: build
build: $(OBJ) build/README.md
	$(CC) -o build/app.exe main.c $<

run:
	./build/app.exe

setup:
	rm -rf build
	mkdir build
	cp README.md build

build/%.o: src/%.c
	$(CC) -o $@ $<
