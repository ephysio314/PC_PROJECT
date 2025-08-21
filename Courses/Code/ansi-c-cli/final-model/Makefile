
CC= -gcc -ansi
LIB_CC= ar rcs

EXE_SRC= main.c
EXE= build/app.exe

MODULE1= module_input
MODULE2= module_print
MODULE3= module_int_conversion

P1= build/
LIB_OBJ= $(P1)$(MODULE1).o $(P1)$(MODULE2).o $(P1)$(MODULE3).o
LIB= $(P1)libmodules.a

LINK= -Lbuild/ -lmodules

all: $(EXE) build/README.md

run: $(EXE)
	./$<

$(EXE): $(EXE_SRC) $(LIB)
	$(CC) -o $@ $^ -Iinc $(LINK)

setup: README.md
	rm -rf build
	mkdir build
	cp README.md build

$(LIB): $(LIB_OBJ)
	$(LIB_CC) $@ $^

$(P1)%.o: src/%.c
	$(CC) -c $< -o $@ -Isrc


