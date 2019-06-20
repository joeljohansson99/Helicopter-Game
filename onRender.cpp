#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <SDL2/SDL_ttf.h>

using namespace std;

void Game::onRender() {

    SDL_RenderCopy(renderer, background, NULL, &rectBackground);

    SDL_RenderCopy(renderer, heli, NULL, &rectHeli);

    SDL_RenderCopy(renderer, hitwalls1, NULL, &rectHitwalls1);

    SDL_RenderCopy(renderer, hitwalls2, NULL, &rectHitwalls2);

    SDL_RenderCopy(renderer, hitwalls3, NULL, &rectHitwalls3);

    SDL_RenderCopy(renderer, text, NULL, &rectText);

    SDL_RenderPresent(renderer);

}
