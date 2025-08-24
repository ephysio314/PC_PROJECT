
P1= project/build/

all: run

run: $(P1)hello.out
	./$<
	
$(P1)hello.out: examples/hello.c project/build/libSDL2.a
	gcc -o $@ $< deps/glad/src/gl.c -Iproject/SDL/include -Ideps/glad/include -Lproject/build -lSDL2 -lSDL2main -lm

project/build/libSDL2.a:
	mkdir project; cd project; git clone -b SDL2 https://github.com/libsdl-org/SDL.git; mkdir build; cmake -S SDL -B build; cmake --build build;
	
clean:
	rm $(P1)hello.out

remove:
	rm -rf project

