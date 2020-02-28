#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>


int main(int argc, char* argv[])
{
    SDL_Window *pWindow=NULL; //Pointeur typedef SDL_Window possède la référence d'un window(Win32)
    SDL_Renderer *pRenderer=NULL; //Pointeur typedef SDL_RENDERER possède la référence du rendu encapsulé dans Window
    //SDL_Texture *pTexture=NULL; //Pointeur typedef SDL_TEXTURE possède la référence l'objet image, matériel ou texture qui sera blité dans le rendu(renderer)


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
