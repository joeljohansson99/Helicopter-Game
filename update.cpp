#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;


void Game::update() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, menu, NULL, &rectMenu);
    SDL_RenderPresent(renderer);
}
