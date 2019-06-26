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
#include <sstream>

void Game::checkHighscore()
{
    string prev;
    int number;
    ifstream ifs("score.txt");

    while(!ifs.eof())
    {
        getline(ifs,prev);;
    }

    istringstream iss (prev);
    iss >> number;


    if (points > number)
    {
        getHighscore();
    }
}

void Game::getHighscore()
{


    ofstream myfile;
    myfile.open ("score.txt");
    myfile << to_string(points);
    myfile.close();
}
