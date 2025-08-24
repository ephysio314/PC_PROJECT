
Tuto ( with branche clone ):
https://www.geeksforgeeks.org/git/how-to-clone-a-branch-in-git/

Creat a directory for the project.

~{
mkdir project
cd project
}~

Github repo example:
https://github.com/libsdl-org/SDL/tree/SDL2

Install git-shell package

~{
sudo apt update
sudo apt install git
}~

If the repository was public

~{
git clone -b SDL2 https://github.com/libsdl-org/SDL.git
ls SDL
}~

Test build using cmake

~{
sudo apt isntall cmake

mkdir build
cmake -S SDL -B build
cmake --build build
ls build
}~

SDL2 Hello-world example

Playlist, Mike Shah, SDL2
https://youtu.be/P3_xhDIP7bc?feature=shared

[Ep. 2] [Setup] SDL Linux command line setup with Glad and OpenGL | Introduction to SDL2
https://www.youtube.com/watch?v=P3_xhDIP7bc&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=2

Download the glad dependancy:

Goto:
    https://github.com/Dav1dde/glad

Search in the main-page the "glad1 generator"
It send to a file generator:
    https://gen.glad.sh/

Setup:
    Generator: C/C++

APIs:
    gl version 4.6

On the right change compatible to core.

Extention:
    ADD ALL

Example of SDL2 code:
    https://github.com/Dav1dde/glad/blob/glad2/example/c/gl_sdl2.c

Below check:
    loader

Click on generate.

Download the zip.
Extract.
Creat a "deps" directory and add to it.

Note:
    Need the source one, not the "header-only"
    because have issue.
    Need to include the header and add the source ot the build.

Creat the file "main.c" inside of "examples:

~{
#include <stdlib.h>
#include <stdio.h>

#include <glad/gl.h>
#include <SDL.h>
#include <SDL_opengl.h>


const GLuint WIDTH = 800, HEIGHT = 600;

int main(void) {
    // code without checking for errors
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window *window = SDL_CreateWindow(
        "[glad] GL with SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    SDL_GLContext context = SDL_GL_CreateContext(window);

    int version = gladLoadGL((GLADloadfunc) SDL_GL_GetProcAddress);
    printf("GL %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));

    int exit = 0;
    while(!exit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    exit = 1;
                    break;
                case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        exit = 1;
                    }
                    break;
                default:
                    break;
            }
        }

        glClearColor(0.7f, 0.9f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
        SDL_Delay(1);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
}~

Compile it using:

~{
gcc -o build/hello.out ../examples/hello.c ../deps/glad/src/gl.c -ISDL/include -I../deps/glad/include -Lbuild -lSDL2 -lm
./build/hello.out
}~

Note:
    "-lm" was for the math-standard-library


