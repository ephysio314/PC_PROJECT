
CC= -gcc -ansi

EXE_SRC= main.c
EXE= build/app.exe

all: $(EXE) build/README.md

run: $(EXE)
	./$<

$(EXE): $(EXE_SRC)
	$(CC) -o $@ $^

setup: README.md
	rm -rf build
	mkdir build
	cp README.md build

