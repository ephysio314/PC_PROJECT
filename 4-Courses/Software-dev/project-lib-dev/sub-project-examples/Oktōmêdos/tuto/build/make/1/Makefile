
# LIBRARIES

P3= lib

LIB1_NAME= mymath
LIB1_INC= -I$(P3)/$(LIB1_NAME)
LIB1_LINK= -Lbuild/$(P3) -l$(LIB1_NAME)
LIB1_BIN= build/$(P3)/lib$(LIB1_NAME).a

$(LIB1_BIN): build/README.md
	cd lib/$(LIB1_NAME) ; make all ; cd ../..

SRC= 
INC= $(LIB1_INC)
LINK= $(LIB1_LINK)

LIB_BIN= $(LIB1_BIN)
LIB_CC= $(INC) $(LINK)

# EXECUTE

CC_VERSION= -std=c89
CC= gcc $(CC_VERSION)

P1= build/examples/
P2= build/tuto/

EXAMPLES= $(P1)hello.out $(P1)mymath.out $(P1)triangle-opengl-glfw.out

all: build/README.md $(EXAMPLES)

$(P1)%.out: examples/%.c build/README.md $(LIB_BIN)
	$(CC) -o $@ $< $(LIB_CC)

build/README.md: README.md
	rm -rf build
	mkdir build
	cp README.md build
	cd build; mkdir examples; cd ..;
	cd build; mkdir lib; cd ..;

remove:
	rm -rf build


