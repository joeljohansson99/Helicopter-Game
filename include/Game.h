#define SDL_MAIN_HANDLED
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WIDTH 1366
#define HEIGHT 768


using namespace std;


class Game
{
    public:
        //MENU
        int getMenu(SDL_Event *event);
        bool getContent();
        // FOR THE WHOLE
        Game();
        bool init();
        void update();
        void cleanup();
        // PLAY
        void getKey(SDL_Event *event);
        int checkLoss();
        void getLast();
        bool getContentPlay();
        int getProgram();
        bool initPlay();
        void onRender();
        void getContentMove();
        void handleEvents();
        void cleanupPlay();
        int gameOver();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;

        SDL_Surface* textSurface;
        SDL_Texture *text;
        SDL_Rect rectText;
        TTF_Font* font;
        SDL_Color fontColor;

        bool running =true;

        int mouseX;
        int mouseY;

        int x1, x2, x3;
        double y=380;
        int randomY1= 300, randomY2=500, randomY3=100;
        int points=0;
        //MENU
        SDL_Texture *menu;
        SDL_Rect rectMenu;
        //PLAY
        SDL_Texture *background;
        SDL_Rect rectBackground;

        SDL_Texture *heli;
        SDL_Rect rectHeli;

        SDL_Texture *hitwalls1;
        SDL_Rect rectHitwalls1;

        SDL_Texture *hitwalls2;
        SDL_Rect rectHitwalls2;

        SDL_Texture *hitwalls3;
        SDL_Rect rectHitwalls3;

        SDL_Texture *game_over;
        SDL_Rect rectGameover;


};

#endif // GAME_H
