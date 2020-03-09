#include "sdl.h"
#include "circle.h"

int main(int argc, char* argv[])
{
    SDL_Manager SDLManager;

    SDLManager.pWindow=NULL; //Pointeur typedef SDL_Window possède la référence d'un window(Win32)
    SDLManager.pRenderer=NULL; //Pointeur typedef SDL_RENDERER possède la référence du rendu encapsulé dans Window

    SDL_Rect rectForSurface = {200,200,150,150};
    SDL_Rect emptySquare = {400,200,150,150};
    SDL_Rect filledSquare = {600,200,150,150};

    //radius of the circle
    int r = 100;
    //x coordinate of the point to place
    int x = 0;
    //y coordinate of the point to place
    int y = r;
    //decision parameter to decide where we should place the pixel according to Bresenham's algorithm
    int d = 3 - (2*r);
    //x coordinate of the center of the circle 1
    int xc1 = 250;
    //y coordinate of the center of the circle 1
    int yc1 = 500;

    //x coordinate of the center of the circle 2
    int xc2 = 500;
    //y coordinate of the center of the circle 2
    int yc2 = 500;




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

    	//red background
    	SDL_SetRenderDrawColor(SDLManager.pRenderer,255,0,0,SDL_ALPHA_OPAQUE);
    	SDL_RenderClear(SDLManager.pRenderer);
    	//setting back the color to black in order to draw
    	SDL_SetRenderDrawColor(SDLManager.pRenderer,0,0,0,SDL_ALPHA_OPAQUE);
    	//drawing empty square
    	SDL_RenderDrawRect(SDLManager.pRenderer,&emptySquare);
    	//drawing filled square
    	SDL_RenderFillRect(SDLManager.pRenderer,&filledSquare);
    	//Drawing empty circle according to Bresenham's algorithm
    	DrawEmptyCircle(x,y,xc1,yc1,d,SDLManager.pRenderer);

    	//drawing filled circle
    	DrawFilledCircle(x,y,r,xc2,yc2,SDLManager.pRenderer);

    	//Drawing a line
    	SDL_RenderDrawLine(SDLManager.pRenderer,700,500,800,600);


    	//creating the surface, changing it to a texture and displaying it
    	SDL_Surface *myBMP = SDL_LoadBMP("chat.bmp");
    	SDL_Texture *BMPintoTexture = SDL_CreateTextureFromSurface(SDLManager.pRenderer,myBMP);
	    SDL_RenderCopy(SDLManager.pRenderer,BMPintoTexture,NULL,&rectForSurface);

	    //updating the render to display everything we drew
	    SDL_RenderPresent(SDLManager.pRenderer);
	    SDL_Delay(5000);

	    //we destroy in the opposite order that we created things
	    SDL_DestroyTexture(BMPintoTexture);
	    SDL_FreeSurface(myBMP);

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
