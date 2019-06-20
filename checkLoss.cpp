#define SDL_MAIN_HANDLED
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

int Game::checkLoss(){
    if (randomY1-53<=y && y <= randomY1+234 && x1>=250-30 && x1<=250+144){
        return -1;
    }
    else if (randomY2-53<=y && y <= randomY2+234 && x2>=250-30 && x2<=250+144){
        return -1;
    }
    else if (randomY3-53<=y && y <= randomY3+234 && x3>=250-30 && x3<=250+144){
        return -1;
    }
    return 1;
}

