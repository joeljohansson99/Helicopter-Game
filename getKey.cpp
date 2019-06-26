#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

void Game::getKey(SDL_Event *event){
    switch(event->key.keysym.sym)
    {
    case SDLK_UP:
        y-=8;
        break;
    }
}
