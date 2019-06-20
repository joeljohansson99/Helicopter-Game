#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <conio.h>
#include <windows.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

int Game::gameOver(){
    if (init()==false)
    {
        return -1;
    }
    int w=0, h=0;
    game_over = IMG_LoadTexture(renderer,"Images/game_over.png");
    SDL_QueryTexture(game_over, NULL, NULL, &w, &h);
    rectGameover.x = 0; rectGameover.y = 0; rectGameover.w = w; rectGameover.h = h;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, game_over, NULL, &rectGameover);
    SDL_RenderPresent(renderer);

    Sleep(1000);

    SDL_DestroyTexture(game_over);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
}

