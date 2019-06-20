#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

using namespace std;


void Game::getContentMove() {
    int w=0, h=0;
    hitwalls1 = IMG_LoadTexture(renderer,"Images/hitwalls.png");
    SDL_QueryTexture(hitwalls1, NULL, NULL, &w, &h);
    rectHitwalls1.x = x1; rectHitwalls1.y = randomY1; rectHitwalls1.w = w; rectHitwalls1.h = h;

    hitwalls2 = IMG_LoadTexture(renderer,"Images/hitwalls.png");
    SDL_QueryTexture(hitwalls2, NULL, NULL, &w, &h);
    rectHitwalls2.x = x2; rectHitwalls2.y = randomY2; rectHitwalls2.w = w; rectHitwalls2.h = h;

    hitwalls3 = IMG_LoadTexture(renderer,"Images/hitwalls.png");
    SDL_QueryTexture(hitwalls3, NULL, NULL, &w, &h);
    rectHitwalls3.x = x3; rectHitwalls3.y = randomY3; rectHitwalls3.w = w; rectHitwalls3.h = h;

    heli = IMG_LoadTexture(renderer,"Images/heli.png");
    SDL_QueryTexture(heli, NULL, NULL, &w, &h);
    rectHeli.x = 250; rectHeli.y = y; rectHeli.w = w; rectHeli.h = h;

    string score = "SCORE: " + to_string(points);

    textSurface = TTF_RenderText_Solid(font,score.c_str(), fontColor);
    text = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_QueryTexture(text, NULL, NULL, &w, &h);
    rectText.x = WIDTH/2 -70; rectText.y = 0; rectText.w = w; rectText.h = h;
}

