#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
using namespace std;


bool Game::getContentPlay(){

    int w=0,h=0;

    background = IMG_LoadTexture(renderer,"Images/background.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rectBackground.x = 0; rectBackground.y = 0; rectBackground.w = w; rectBackground.h = h;

    return true;
}

