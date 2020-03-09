#ifndef SDL_H
#define SDL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

typedef struct sdl_manager
{
     SDL_Window *pWindow;
     SDL_Renderer *pRenderer;
     SDL_Texture *ptexture;
     SDL_Surface *psurface;
}SDL_Manager; 




#endif // SDL_H
