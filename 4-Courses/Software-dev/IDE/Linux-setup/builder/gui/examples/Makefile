
#SDL

LIB1_BUILD= build-sdl/
LIB1_BIN= $(LIB1_BUILD)libSDL2.a

$(LIB1_BIN):
	cd ../lib; make $@

LIB1_EXAMPLE= hello-sdl.out

$(LIB1_EXAMPLE): hello-sdl.c $(LIB1_BIN) build/README.md
	gcc -o build/$@ $< ../deps/glad/src/gl.c -I../deps/glad/include -I../lib/SDL/include -L../lib/$(LIB1_BUILD) -lSDL2 -lm

all: $(LIB1_EXAMPLE)

build/README.md: README.md
	mkdir build
	cp README.md build

remove:
	rm -rf build

