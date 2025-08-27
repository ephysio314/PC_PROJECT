
# LIBRARIES

P3= lib

LIB1_NAME= mymath
LIB1= build/$(P3)/lib$(LIB1_NAME).a

LIB1_SRC= $(P3)/$(LIB1_NAME)/$(LIB1_NAME).c
LIB1_INC= -I$(P3)/$(LIB1_NAME)
LIB1_LINK= -Lbuild/$(P3) -l$(LIB1_NAME)

SRC= $(LIB1_SRC)
INC= $(LIB1_INC)
LINK= $(LIB1_LINK)

LIB_BIN= $(LIB1)
LIB_CC= $(INC) $(LINK)

# EXECUTE

CC_VERSION= -std=c89
CC= gcc $(CC_VERSION)

P1= build/examples/
P2= build/tuto/

EXAMPLES= $(P1)hello.out

all: $(EXAMPLES)

$(P1)%.out: examples/%.c build/README.md $(LIB_BIN)
	$(CC) -o $@ $< $(LIB_CC)

$(P2)%.out: tuto/%.c build/README.md $(LIB_BIN)
	$(CC) -o $@ $< $(LIB_CC)

$(LIB1): $(LIB1_SRC)
	ar rcs $@ $^

build/README.md: README.md
	rm -rf build
	mkdir build
	cp README.md build
	cd build; mkdir examples; cd ..;
	cd build; mkdir tuto; cd ..;
	cd build; mkdir lib; cd ..;

remove:
	rm -rf build


