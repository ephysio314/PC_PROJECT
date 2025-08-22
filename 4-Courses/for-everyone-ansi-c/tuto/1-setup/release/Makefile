
P1= build

CC= gcc -ansi
MAIN_OUT= $(P1)/app.exe

all: $(MAIN_OUT)

run: $(MAIN_OUT)
	./$<
	
clean: $(MAIN_OUT)
	rm $<

$(MAIN_OUT): main.c
	$(CC) -o $@ $<

setup: README.md
	rm -rf $(P1)
	mkdir $(P1)
	cp $< $(P1)

