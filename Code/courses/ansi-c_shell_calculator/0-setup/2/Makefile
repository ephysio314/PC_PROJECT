
CC= -gcc -ansi

EXE_SRC= main.c
EXE= build/app.exe

P1= build/
LIB_OBJ= $(P1)mymath.o
LIB= $(P1)libmymath.a
LIB_CC= ar rcs

LINK= -Lbuild/ -lmymath

all: $(EXE) build/README.md

run: $(EXE)
	./$<

$(EXE): $(EXE_SRC)
	$(CC) -o $@ $^ $(LINK)

setup: README.md
	rm -rf build
	mkdir build
	cp README.md build

$(LIB): $(LIB_OBJ)
	$(LIB_CC) $@ $^

$(P1)%.o: src/%.c
	$(CC) -c $< -o $@ -Isrc


