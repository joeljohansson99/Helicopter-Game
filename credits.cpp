#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>
#include <fstream>
#include <string>

using namespace std;

void Game::credits(){
        cleanup();
    if (init()==false)
    {
        cout << "Error Init";
    }
    int w=0, h=0;
    credit = IMG_LoadTexture(renderer,"Images/credits.png");
    SDL_QueryTexture(credit, NULL, NULL, &w, &h);
    rectCredit.x = 0; rectCredit.y = 0; rectCredit.w = w; rectCredit.h = h;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, credit, NULL, &rectCredit);
    SDL_RenderPresent(renderer);

    SDL_bool credStop = SDL_FALSE;

    while (!credStop) {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            if (event.type==SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&mouseX, &mouseY);
            }
            switch(event.type)
            {
            case SDL_QUIT:
                credStop = SDL_FALSE;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(mouseX > 1195 && mouseX < 1332 && mouseY > 680 && mouseY < 730)
                {
                    credStop = SDL_TRUE;
                    break;
                }
            }
        }
    }
    SDL_DestroyTexture(credit);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Game again;
}
