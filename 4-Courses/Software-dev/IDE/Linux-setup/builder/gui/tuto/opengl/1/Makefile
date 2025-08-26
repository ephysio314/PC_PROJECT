
PATH_BACK= ../../../

#GLFW

LIB1_BUILD= build-glfw/src/
LIB1_BIN= $(LIB1_BUILD)libglfw3.a

$(PATH_BACK)lib/$(LIB1_BIN):
	cd $(PATH_BACK)lib; make $(LIB1_BIN); cd $(PATH_BACK);

LIB1_EXAMPLE= app.out

#SETUP

BIN= $(PATH_BACK)lib/$(LIB1_BIN) $(LIB1_EXAMPLE)

$(LIB1_EXAMPLE): main.c $(PATH_BACK)lib/$(LIB1_BIN) build/README.md
	gcc -o build/$@ $< $(PATH_BACK)deps/glad/src/gl.c -I$(PATH_BACK)deps/glad/include -I$(PATH_BACK)lib/glfw/include -L$(PATH_BACK)lib/$(LIB1_BUILD) -lglfw3 -lX11 -lm

P1= build/examples/
EXAMPLES= $(P1)hello.out

build/examples/%.out: examples/%.c $(PATH_BACK)lib/$(LIB1_BIN) build/README.md
	gcc -o $@ $< $(PATH_BACK)deps/glad/src/gl.c -I$(PATH_BACK)deps/glad/include -I$(PATH_BACK)lib/glfw/include -L$(PATH_BACK)lib/$(LIB1_BUILD) -lglfw3 -lX11 -lm

all: $(BIN) $(EXAMPLES)

build/README.md: README.md
	mkdir build
	cp README.md build
	cd build; mkdir examples; cd ..;

remove:
	rm -rf build

