#include <stdio.h>

#include <SDL.h>

const unsigned int WIDTH = 800, HEIGHT = 600;

int main(int _argc, char ** _argv) {
    // code without checking for errors
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window *win = SDL_CreateWindow(
        "Draw 2d with SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    SDL_Renderer * ctx = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
 
    int exit = 0;
    while(!exit) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            switch(ev.type) {
                case SDL_QUIT:
                    exit = 1;
                    break;
                case SDL_KEYUP:
                    if (ev.key.keysym.sym == SDLK_ESCAPE) {
                        exit = 1;
                    }
                    break;
                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(ctx, 0, 128, 128, 255);
        SDL_RenderClear(ctx);

        SDL_RenderPresent(ctx);
    }

    SDL_DestroyRenderer(ctx);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}


