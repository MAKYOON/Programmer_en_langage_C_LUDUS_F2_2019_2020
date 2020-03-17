#include "game.h"

void LoadMapTiles(Map *map)
{
	int id = 0;
	map->tiles = malloc(map->nbtiles_x*map->nbtiles_y*sizeof(Tile));

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

void DisplayMap(FILE *fileLevel, SDL_Texture *tileset, Map *map, SDL_Manager *sdlManager)
{
	for (int j = 0; j < map->max_y_map; j++)
	{
		for (int i = 0; i < map->max_x_map; i++)
		{
			SDL_Rect dstrect = {(i*map->width_tile)*SCALE,(j*map->height_tile)*SCALE,map->width_tile*SCALE,map->height_tile*SCALE};
			int temp;
			fscanf(fileLevel,"%d",&temp);
			SDL_RenderCopy(sdlManager->pRenderer,tileset,&(map->tiles[temp].tileRect),&dstrect);
		}
	}
	//updating the render to display everything we drew
	SDL_RenderPresent(sdlManager->pRenderer);
}
