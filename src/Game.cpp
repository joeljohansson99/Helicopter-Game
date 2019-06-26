#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

Game::Game(): window(NULL), menu(NULL)
{
    fontColor = {8,108,65};
    highscoreColor = {200, 235, 0};
    getMenu(&event);
}

void Game::handleEvents()
{
    SDL_PollEvent( &event );

    if (event.type == SDL_QUIT)
    {
        cleanupPlay();
    }

    if ( event.type == SDL_KEYDOWN )
    {
        getKey(&event);
    }
    else
    {
       y+=6;
    }
}
