#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;


bool Game::getContent(){
    int w=0,h=0;
    menu = IMG_LoadTexture(renderer,"Images/menu.png");
    SDL_QueryTexture(menu, NULL, NULL, &w, &h);
    rectMenu.x = 0; rectMenu.y = 0; rectMenu.w = w; rectMenu.h = h;
    return 1;
}
