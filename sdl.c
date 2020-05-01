#include "sdl.h"


int InitAllSDL(SDL_Window **pWindow, SDL_Renderer **pRenderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        //create window
        *pWindow = SDL_CreateWindow("Pong",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH ,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);

        if (pWindow!=NULL)
        {
            //create renderer
           *pRenderer = SDL_CreateRenderer(*pWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
        }

        if(TTF_Init() == -1)
        {
            fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
            exit(EXIT_FAILURE);
        }
        return 1;
    }
    else
        return 0;
}

void QuitEverything(SDL_Texture **paddle1, SDL_Texture **paddle2, SDL_Window **pWindow, SDL_Renderer **pRenderer)
{
        TTF_Quit();
		SDL_DestroyTexture(*paddle1);
		SDL_DestroyTexture(*paddle2);
		SDL_DestroyRenderer(*pRenderer);
		SDL_DestroyWindow(*pWindow);
		SDL_Quit();
}
