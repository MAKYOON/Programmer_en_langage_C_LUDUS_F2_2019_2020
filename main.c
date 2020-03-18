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


		//file which has the level
		FILE *file = fopen("level.txt","r");
		//we load the tileset as a PNG in a surface and convert it to a texture
		SDL_Surface *myPNG = IMG_Load("tileset.png");
		SDL_Texture *tileset = SDL_CreateTextureFromSurface(SDLManager.pRenderer,myPNG);
		SDL_FreeSurface(myPNG);
		//calling our function to fill the array of tiles for the map
		LoadMapTiles(map);
		//this is to render a lightblue background
		SDL_SetRenderDrawColor(SDLManager.pRenderer,0,153,219,SDL_ALPHA_OPAQUE);
		SDL_RenderClear(SDLManager.pRenderer);
		//we display the map
		DisplayMap(file,tileset,map,&SDLManager);
		//slight delay before closing everything
        SDL_Delay(10000);

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
