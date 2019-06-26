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

int Game::displayHighscore(SDL_Event *event)
{
    cleanup();
    if (init()==false)
    {
        cout << "Error Init";
    }

    string prev;
    ifstream ifs("score.txt");

    while(!ifs.eof())
    {
        getline(ifs,prev);;
    }

    font = TTF_OpenFont("font.ttf", 60);
    if (font==NULL){
        cout << "Error Font" << endl;
    }
    int w=0, h=0;
    highScore = IMG_LoadTexture(renderer,"Images/highscore.png");
    SDL_QueryTexture(highScore, NULL, NULL, &w, &h);
    rectHighscore.x = 0; rectHighscore.y = 0; rectHighscore.w = w; rectHighscore.h = h;

    scoreSurface = TTF_RenderText_Solid(font,prev.c_str(), highscoreColor);
    hsInput = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_QueryTexture(hsInput, NULL, NULL, &w, &h);
    rectHsInput.x = WIDTH/2 -45; rectHsInput.y = 300; rectHsInput.w = w; rectHsInput.h = h;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, highScore, NULL, &rectHighscore);
    SDL_RenderCopy(renderer, hsInput, NULL, &rectHsInput);
    SDL_RenderPresent(renderer);

    while (running==true)
    {

        while (SDL_PollEvent(event))
        {
            if (event->type == SDL_QUIT)
            {
                running = false;
            }
            if (event->type==SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&mouseX, &mouseY);
            }
            switch(event->type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(mouseX > 1110 && mouseX < 1256 && mouseY > 654 && mouseY < 720)
                {
                    running = false;
                    break;
                }
            }
        }
    }

    SDL_DestroyTexture(highScore);
    SDL_DestroyTexture(hsInput);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Game again;

    return 1;
}
