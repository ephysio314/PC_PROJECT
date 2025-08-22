
MAIN_OUT= app.exe

all: $(MAIN_OUT)

run: $(MAIN_OUT)
	./$<
	
clean: $(MAIN_OUT)
	rm $<

$(MAIN_OUT): main.c
	gcc -ansi -o $@ $<

