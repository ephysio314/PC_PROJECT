
PATH_BACK= ../../../

#LIB1: GLFW

LIB1_BUILD= build-glfw/src/
LIB1_BIN= $(LIB1_BUILD)libglfw3.a
LIB1= $(PATH_BACK)lib/$(LIB1_BIN)

LIB1_INC= -I$(PATH_BACK)lib/glfw/include 
LIB1_LINK= -L$(PATH_BACK)lib/$(LIB1_BUILD) -lglfw3 -lX11 -lm

$(LIB1):
	cd $(PATH_BACK)lib; make $(LIB1_BIN); cd $(PATH_BACK);

LIB2_SRC= $(PATH_BACK)deps/glad/src/gl.c
LIB2_INC= -I$(PATH_BACK)deps/glad/include

LIB3_SRC= lib/gui/gui.c
LIB3_INC= lib/gui/gui.h

#SETUP

P1= build/examples/
EXAMPLES= $(P1)hello.out

DEPS1_REQUIRED_LIB= $(LIB1)
DEPS1_SRC= $(LIB3_SRC) $(LIB2_SRC)
DEPS1_INC= $(LIB3_INC) $(LIB2_INC) $(LIB1_INC)
DEPS1_LINK= $(LIB1_LINK)
DEPS1= $(DEPS1_SRC) $(DEPS1_INC) $(DEPS1_LINK)
build/examples/%.out: examples/%.c $(DEPS1_REQUIRED_LIB) build/README.md
	gcc -o $@ $< -Ilib $(DEPS1)

BIN= $(DEPS1_REQUIRED_LIB) $(EXAMPLES)

all: $(BIN)

build/README.md: README.md
	mkdir build
	cp README.md build
	cd build; mkdir examples; cd ..;

remove:
	rm -rf build

