
/*
https://wiki.libsdl.org/SDL2/SDL_RenderCopy
https://wiki.libsdl.org/SDL2/SDL_QueryTexture
*/

#include <stdio.h>

#include <SDL.h>

#include <SDL_image.h>

struct Img{
	SDL_Texture * texture;
	SDL_Rect box;
};

struct Img CreateImage(SDL_Renderer * _ctx, const char * _path){
	struct Img return_val = (struct Img){0};
	SDL_Surface * surface = IMG_Load(_path);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(_ctx, surface);
	SDL_FreeSurface(surface);
	
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	
	return_val.texture = texture;
	return_val.box.w = w;
	return_val.box.h = h;
	return return_val;
}

void DrawImg(SDL_Renderer * _ctx, struct Img _img){
	SDL_RenderCopy(_ctx, _img.texture, NULL, _img.box);
}

const unsigned int WIDTH = 800, HEIGHT = 600;

int main(int _argc, char ** _argv) {
    // code without checking for errors
    SDL_Init(SDL_INIT_VIDEO);
    
    IMG_Init(IMG_INIT_PNG);
    
    SDL_Window *win = SDL_CreateWindow(
        "Draw 2d images with SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    SDL_Renderer * ctx = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    
    /*
     Note: App should be run from the root directory containing "assets".
    */
    
    const char img_path[FILENAME_MAX] = "assets/img/cat.png";
    struct Img img = CreateImage(ctx, img_path);
 
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
        
        DrawImg(ctx, img);

        SDL_RenderPresent(ctx);
    }

    SDL_DestroyTexture(img.texture);
    
    SDL_DestroyRenderer(ctx);
    SDL_DestroyWindow(win);
    
    IMG_Quit();
    SDL_Quit();

    return 0;
}


