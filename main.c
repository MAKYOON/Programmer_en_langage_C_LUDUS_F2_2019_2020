#include "sdl.h"
#include "circle.h"
#include "game.h"

int main(int argc, char* argv[])
{
	SDL_Manager SDLManager;

	SDLManager.pWindow=NULL; //Pointeur typedef SDL_Window possède la référence d'un window(Win32)
	SDLManager.pRenderer=NULL; //Pointeur typedef SDL_RENDERER possède la référence du rendu encapsulé dans Window

	Map *map = malloc(sizeof(*map));
	map->nbtiles_x = NB_TILESET_X;
	map->nbtiles_y = NB_TILESET_Y;
	map->max_x_map = NB_TILES_MAP_X;
	map->max_y_map = NB_TILES_MAP_Y;
	map->width_tile = WIDTH_TILESET/map->nbtiles_x;
	map->height_tile = HEIGHT_TILESET/map->nbtiles_y;
	map->scrollRect.x = 0;
	map->scrollRect.y = 0;
	//we defined TRUE as 1 and FALSE as 0
	int exit = FALSE;

	//Initialization of SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		//create window
		SDLManager.pWindow = SDL_CreateWindow("SDL_Application",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,NB_TILES_MAP_X*map->width_tile*SCALE,NB_TILES_MAP_Y*map->height_tile*SCALE,SDL_WINDOW_SHOWN);

		if (SDLManager.pWindow!=NULL)
		{
			//create renderer
			SDLManager.pRenderer = SDL_CreateRenderer(SDLManager.pWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
		}

		SDL_Event event;

		//we load the tileset as a PNG in a surface and convert it to a texture
		SDL_Surface *myPNG = IMG_Load("tileset.png");
		SDL_Texture *tileset = SDL_CreateTextureFromSurface(SDLManager.pRenderer,myPNG);
		SDL_FreeSurface(myPNG);
		//calling our function to fill the array of tiles for the map
		LoadMapTiles(map);

		const Uint8 *keyStates = SDL_GetKeyboardState(NULL);

		while (exit != TRUE)
		{
			//we check if there's an event, if so we store it into our event variable (which is of type SDL_Event)
			while(SDL_PollEvent(&event))
			{
			  switch(event.type)
			  	{
			  		//we check if it's an input, in which case we handle the scrolling
				    case SDL_KEYDOWN:
				    {
				    	//using SCANCODE, the SCANCODE W corresponds to the KEYCODE Z. so the input for us (using AZERTY keyboard) is Z.
				    	if (keyStates[SDL_SCANCODE_W] && keyStates[SDL_SCANCODE_A])
				    	{
				    		map->scrollRect.y -= SCROLL_SPEED;
				    		map->scrollRect.x -= SCROLL_SPEED;
				    	}
				    	else if (keyStates[SDL_SCANCODE_W] && keyStates[SDL_SCANCODE_D])
				    	{
				    		map->scrollRect.y -= SCROLL_SPEED;
				    		map->scrollRect.x += SCROLL_SPEED;
				    	}
				    	else if (keyStates[SDL_SCANCODE_S] && keyStates[SDL_SCANCODE_A])
				    	{
				    		map->scrollRect.y += SCROLL_SPEED;
				    		map->scrollRect.x -= SCROLL_SPEED;
				    	}
				    	else if (keyStates[SDL_SCANCODE_S] && keyStates[SDL_SCANCODE_D])
				    	{
				    		map->scrollRect.y += SCROLL_SPEED;
				    		map->scrollRect.x += SCROLL_SPEED;
				    	}
				    	else if (keyStates[SDL_SCANCODE_W])
				    		map->scrollRect.y -= SCROLL_SPEED;
				    	else if (keyStates[SDL_SCANCODE_A])
				    		map->scrollRect.x -= SCROLL_SPEED;
				    	else if (keyStates[SDL_SCANCODE_S])
				    		map->scrollRect.y += SCROLL_SPEED;
				    	else if (keyStates[SDL_SCANCODE_D])
				    		map->scrollRect.x += SCROLL_SPEED;
				    	else if (keyStates[SDL_SCANCODE_ESCAPE])
				    		exit = TRUE;

				    	break;
				    }
				    //this is when the user clicks on the red cross to terminate the SDL_Window, in this case we exit the program.
				    case SDL_QUIT:
				    {
				    	exit = TRUE;
				    	break;
				    }
			    }
			}
			SDL_RenderClear(SDLManager.pRenderer);
			DisplayMap("level.txt",tileset,map,&SDLManager);
		}
			SDL_DestroyTexture(tileset);
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
