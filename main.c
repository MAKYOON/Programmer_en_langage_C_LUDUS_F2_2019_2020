#include "sdl.h"
#include "circle.h"
#include <SDL2/SDL_Image.h>

int main(int argc, char* argv[])
{
    SDL_Manager SDLManager;

    SDLManager.pWindow=NULL; //Pointeur typedef SDL_Window possède la référence d'un window(Win32)
    SDLManager.pRenderer=NULL; //Pointeur typedef SDL_RENDERER possède la référence du rendu encapsulé dans Window

	int quit = 0;

    //Initialisation d'SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
    	//create window
    	SDLManager.pWindow = SDL_CreateWindow("SDL_Application",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);

    	if (SDLManager.pWindow!=NULL)
    	{
    		//create renderer
    		SDLManager.pRenderer = SDL_CreateRenderer(SDLManager.pWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    	}
		//loading a PNG with IMG_Load function, transforming it into a texture and rendering it
	    SDL_Surface *myPNG = IMG_Load("character.png");
	    SDL_Texture *PNGintoTexture = SDL_CreateTextureFromSurface(SDLManager.pRenderer,myPNG);
		while (!quit)
	    {	
	    	//number of miliseconds since we started the program
	    	int ticks = SDL_GetTicks();
	    	//this is the time it takes to render one image from the sprite
	    	int sprite = (ticks/200) % 8;
	    	//the rect we cut from the sprite
    		SDL_Rect srcrect = { sprite*33 , 0, 34, 40 };
    		//the rect in which we paste the sprite
			SDL_Rect dstrect = { 200, 200, 34, 40};
	     	//red background
	    	SDL_SetRenderDrawColor(SDLManager.pRenderer,255,0,0,SDL_ALPHA_OPAQUE);
	    	SDL_RenderClear(SDLManager.pRenderer);
		    SDL_RenderCopy(SDLManager.pRenderer,PNGintoTexture,&srcrect,&dstrect);

		    //updating the render to display everything we drew
		    SDL_RenderPresent(SDLManager.pRenderer);
		
	    }
	    
    	SDL_DestroyRenderer(SDLManager.pRenderer);
    	SDL_DestroyWindow(SDLManager.pWindow);
    	SDL_Quit();

    }
    else
    {
    	return 0;
    }


    return 0;



}
