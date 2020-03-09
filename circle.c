#include "circle.h"

void DrawPoint(int xc, int yc, int x, int y, SDL_Renderer *pRenderer)
//draw a point in all of the quadrants of a circle
//xc and yc being the center of the circle
{
	SDL_RenderDrawPoint(pRenderer,xc+x,yc+y);
	SDL_RenderDrawPoint(pRenderer,xc-x,yc+y);
	SDL_RenderDrawPoint(pRenderer,xc+x,yc-y);
	SDL_RenderDrawPoint(pRenderer,xc-x,yc-y);
	SDL_RenderDrawPoint(pRenderer,xc+y,yc+x);
	SDL_RenderDrawPoint(pRenderer,xc-y,yc+x);
	SDL_RenderDrawPoint(pRenderer,xc+y,yc-x);
	SDL_RenderDrawPoint(pRenderer,xc-y,yc-x);
}

void DrawEmptyCircle(int x, int y, int xc,int yc,int d,SDL_Renderer *pRenderer)
{
	DrawPoint(xc,yc,x,y,pRenderer);
	while (x <= y)
	{
		x++;
		if (d<0)
			d += (4*x) + 6;
		else
		{
			d += 4*(x-y) + 10;
			y--;
		}
		DrawPoint(xc,yc,x,y,pRenderer);
	}
}

void DrawFilledCircle(int x, int y, int r, int xc, int yc, SDL_Renderer *pRenderer)
{
	for (y = -r; y <= r; y++)
	{
		for (x = -r; x <= r; x++)
		{
			if(x*x+y*y <= r*r)
				SDL_RenderDrawPoint(pRenderer,xc+x,yc+y); 
		}
	}
}

