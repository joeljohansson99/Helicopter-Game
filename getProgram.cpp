#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

int Game::getProgram()
{
    srand(time(NULL));
    cleanup();
    if (init()==false)
    {
        return -1;
    }

    if (getContentPlay()==false)
    {
        return -1;
    }
    points=0;
    x1=WIDTH;
    x2=WIDTH + WIDTH/3;
    x3=WIDTH + (2*WIDTH)/3;
    y=380;

    font = TTF_OpenFont("font.ttf", 30);
    if (font==NULL){
        cout << "Error Font" << endl;
    }

    while (true)
    {
        Sleep(8);
        if(y<0){
            y+=4;
        }
        if(y>HEIGHT-53){
            y-=3;
        }

        handleEvents();
        x1-=5;
        x2-=5;
        x3-=5;
        if (x2<-34){x2=WIDTH; randomY2 = rand()%534; points++;}
        if (x1<-34){x1=WIDTH; randomY1 = rand()%534; points++;}
        if (x3<-34){x3=WIDTH; randomY3 = rand()%534; points++;}
        getContentMove();

        onRender();

        getContentMove();
        if (checkLoss()==-1) {
            break;
        }
    }

    cleanupPlay();

    if (gameOver()==-1){
        return -1;

    }

    getMenu(&event);

    return -1;
}
