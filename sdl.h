#ifndef SDL_H
#define SDL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "SDL2/SDL_ttf.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct sdl_manager
{
     SDL_Window *pWindow;
     SDL_Renderer *pRenderer;
     SDL_Texture *ptexture;
     SDL_Surface *psurface;
}SDL_Manager;

extern int InitAllSDL(SDL_Window **pWindow, SDL_Renderer **pRenderer);
extern void QuitEverything(SDL_Texture **paddle1, SDL_Texture **paddle2, SDL_Window **pWindow, SDL_Renderer **pRenderer);


#endif // SDL_H
