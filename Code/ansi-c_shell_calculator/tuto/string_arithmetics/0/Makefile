
CC_VERSION= -std=c89
CC_FLAGS= $(CC_VERSION)
CC= -gcc $(CC_FLAGS)

SRC= main.c deps/int_conversion.c
EXE= a.exe

exe: $(EXE)

$(EXE): $(SRC)
	$(CC) -o $@ $^

clear:
	rm $(EXE)
