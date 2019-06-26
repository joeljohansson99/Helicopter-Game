#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;


int Game::getMenu(SDL_Event *event)
{
    if (init()==false)
    {
        return -1;
    }
    if (getContent()==false)
    {
        return -1;
    }
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
                if(mouseX > 1000 && mouseX < 1200 && mouseY > 100 && mouseY < 180)
                {
                    getProgram();
                    break;
                }
                else if (mouseX > 1000 && mouseX < 1275 && mouseY > 284 && mouseY < 366)
                {
                    displayHighscore(event);
                    break;
                }
                else if (mouseX > 1022 && mouseX < 1215 && mouseY > 447 && mouseY < 510)
                {
                    credits();
                    break;
                }
            }
        }

        update();
    }
    cleanup();
    return 0;
}
