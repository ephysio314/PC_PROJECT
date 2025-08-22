
all: app.exe

run: app.exe
	./$<
	
clean: app.exe
	rm $<

app.exe: main.c
	gcc -ansi -o $@ $<

