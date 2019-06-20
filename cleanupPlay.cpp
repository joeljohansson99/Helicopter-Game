#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;


void Game::cleanupPlay(){
    SDL_DestroyTexture(hitwalls1);
    SDL_DestroyTexture(hitwalls2);
    SDL_DestroyTexture(hitwalls3);
    SDL_DestroyTexture(heli);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(text);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
