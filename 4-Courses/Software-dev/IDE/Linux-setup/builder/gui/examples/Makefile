
#SDL ( work )

LIB1_BUILD= build-sdl/
LIB1_BIN= $(LIB1_BUILD)libSDL2.a

../lib/$(LIB1_BIN):
	cd ../lib; make $(LIB1_BIN); cd ..;

LIB1_EXAMPLE= hello-sdl.out

$(LIB1_EXAMPLE): hello-sdl.c ../lib/$(LIB1_BIN) build/README.md
	gcc -o build/$@ $< ../deps/glad/src/gl.c -I../deps/glad/include -I../lib/SDL/include -L../lib/$(LIB1_BUILD) -lSDL2 -lm


#GLFW ( generate glfw lib fail )

LIB2_BUILD= build-glfw/src/
LIB2_BIN= $(LIB2_BUILD)libglfw3.a

../lib/$(LIB2_BIN):
	cd ../lib; make $(LIB2_BIN); cd ..;

LIB2_EXAMPLE= hello-glfw.out

$(LIB2_EXAMPLE): hello-glfw.c ../lib/$(LIB2_BIN) build/README.md
	gcc -o build/$@ $< ../deps/glad/src/gl.c -I../deps/glad/include -I../lib/glfw/include -L../lib/$(LIB2_BUILD) -lglfw3 -lX11 -lm

#SETUP

BIN= ../lib/$(LIB1_BIN) ../lib/$(LIB2_BIN) $(LIB1_EXAMPLE) $(LIB2_EXAMPLE)

all: $(BIN)

build/README.md: README.md
	mkdir build
	cp README.md build

remove:
	rm -rf build

