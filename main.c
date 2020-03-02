#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    SDL_Window *pWindow=NULL; //Pointeur typedef SDL_Window possède la référence d'un window(Win32)
    SDL_Renderer *pRenderer=NULL; //Pointeur typedef SDL_RENDERER possède la référence du rendu encapsulé dans Window

    //Initialisation d'SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
    	//create window
    	pWindow = SDL_CreateWindow("SDL_Application",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);

    	if (pWindow!=NULL)
    	{
    		//create renderer
    		pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    	}

    	SDL_SetRenderDrawColor(pRenderer,255,0,0,SDL_ALPHA_OPAQUE);
    	SDL_RenderClear(pRenderer);
    	
    	SDL_Surface *myBMP = SDL_LoadBMP("chat.bmp");
	    	
	    SDL_RenderPresent(pRenderer);
	    SDL_Delay(5000);
    	SDL_DestroyRenderer(pRenderer);
    	SDL_DestroyWindow(pWindow);
    	SDL_Quit();

    }
    else
    {
    	return 0;
    }


    return 0;

}

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
