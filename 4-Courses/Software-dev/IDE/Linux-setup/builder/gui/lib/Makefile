
LIB1_BUILD= build-sdl/
LIB1_BIN= $(LIB1_BUILD)libSDL2.a
LIB1= SDL
GIT1= https://github.com/libsdl-org/SDL.git
GIT_SUB1= SDL2
$(LIB1_BIN): 
	mkdir $(LIB1_BUILD); git clone -b $(GIT_SUB1) $(GIT1); cmake -S $(LIB1) -B $(LIB1_BUILD); cmake --build $(LIB1_BUILD);
	
LIB2_BUILD= build-glfw/
LIB2_BIN= $(LIB2_BUILD)libglfw3.a
LIB2= glfw
GIT2= https://github.com/glfw/glfw.git
GIT_SUB2= 3.3-stable
$(LIB2_BIN): 
	mkdir $(LIB2_BUILD); git clone -b $(GIT_SUB2) $(GIT2); cmake -S $(LIB2) -B $(LIB2_BUILD); cmake --build $(LIB2_BUILD);
	
all: $(LIB1_BIN) $(LIB2_BIN)

remove:
	rm -rf glfw
	rm -rf SDL
	rm -rf build-glfw
	rm -rf build-sdl

