#ifndef CIRCLE_H
#define CIRCLE_H
#include <SDL2/SDL.h>

extern void DrawPoint(int xc, int yc, int x, int y, SDL_Renderer *pRenderer);
extern void DrawEmptyCircle(int x, int y, int xc,int yc,int d,SDL_Renderer *pRenderer);
extern void DrawFilledCircle(int x, int y, int r, int xc, int yc, SDL_Renderer *pRenderer);

#endif
