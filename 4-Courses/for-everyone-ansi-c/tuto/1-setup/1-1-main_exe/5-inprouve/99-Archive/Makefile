
CC= gcc -ansi
PATH= build
MAIN_OUT= $(PATH)/app.exe

.PHONY: all
all: $(MAIN_OUT)

.PHONY: run
run: $(MAIN_OUT)
	./$<

.PHONY: clean
clean:
	rm $(MAIN_OUT)

.PHONY: setup
setup: README.md
	rm -rf $(PATH); mkdir $(PATH); cp $< $(PATH);

$(MAIN_OUT): main.c
	$(CC) -o $@ $<

