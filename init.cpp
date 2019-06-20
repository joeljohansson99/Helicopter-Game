#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;


bool Game::init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
        cout << "ERROR";
    }
    if((window = SDL_CreateWindow("Helicopter Game", 100, 100, WIDTH, HEIGHT, SDL_RENDERER_PRESENTVSYNC)) == NULL) {
        return false;
        cout << "ERROR Window";
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL){
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init()==-1) {
        return false;
    }


    return true;
}
