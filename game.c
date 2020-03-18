#include "game.h"

void LoadMapTiles(Map *map)
//this function's purpose is to fill the array of tiles in map : each tile in the array will have its rect calculated and its identifier, and then from the tileset we can know which tile it corresponds to
{
	int id = 0;
	//we allocate the memory for the array
	map->tiles = malloc(map->nbtiles_x*map->nbtiles_y*sizeof(Tile));
	//checking if no error
	if (map != NULL)
	{
		 for (int j = 0; j < map->nbtiles_y; j++)
		 {
			for (int i = 0; i < map->nbtiles_x; i++)
			{
				map->tiles[id].tileRect.x = i*map->width_tile;
				map->tiles[id].tileRect.y = j*map->height_tile;
				map->tiles[id].tileRect.w = map->width_tile;
				map->tiles[id].tileRect.h = map->height_tile;
				map->tiles[id].id = id;
				id++;
			}
		 }
	}
}

//this function displays the map, it takes into paramater : !
//the file in which we wrote the identifiers of the tiles to display
//the tileset
//a pointer to the map
//and the SDL_Manager structure in order to access the renderer to display the map
void DisplayMap(char fileName[BUFFER_SIZE], SDL_Texture *tileset, Map *map, SDL_Manager *sdlManager)
{
	//file which has the level
	FILE *file = fopen(fileName,"r");
    SDL_SetRenderDrawColor(sdlManager->pRenderer,0,153,219,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(sdlManager->pRenderer);
	for (int j = 0; j < map->max_y_map; j++)
	{
		for (int i = 0; i < map->max_x_map; i++)
		{
			SDL_Rect dstrect = {((i*map->width_tile)*SCALE) - map->scrollRect.x,((j*map->height_tile)*SCALE) - map->scrollRect.y,map->width_tile*SCALE,map->height_tile*SCALE};
			int temp;
			fscanf(file,"%d",&temp);
			SDL_RenderCopy(sdlManager->pRenderer,tileset,&(map->tiles[temp].tileRect),&dstrect);
		}
	}
	fclose(file);
    SDL_RenderPresent(sdlManager->pRenderer);
}
