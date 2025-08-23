
all: a.exe

run: a.exe
	./$<

a.exe: main.c
	gcc -ansi -o $@ $<

clean: a.exe
	rm $<
