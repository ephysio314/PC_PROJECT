
P1= modules/
MODULES_SRC= $(P1)gl_Shader.c $(P1)gl_CreateShader.c $(P1)gl_ConfigShader.c

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
	gcc -o build/$@ $< $(PATH_BACK)deps/glad/src/gl.c $(MODULES_SRC) -Imodules -I$(PATH_BACK)deps/glad/include -I$(PATH_BACK)lib/glfw/include -L$(PATH_BACK)lib/$(LIB1_BUILD) -lglfw3 -lX11 -lm

all: $(BIN)
	./build/$(LIB1_EXAMPLE)

build/README.md: README.md
	mkdir build
	cp README.md build

remove:
	rm -rf build

