#ifndef GAME_H_DEFINED
#define GAME_H_DEFINED

#include <SDL2/SDL_Image.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "sdl.h"

#define TRUE 1
#define FALSE 0
#define WIDTH_TILESET 112
#define HEIGHT_TILESET 176
#define NB_TILESET_X 7
#define NB_TILESET_Y 11
#define NB_TILES_MAP_X 12
#define NB_TILES_MAP_Y 6
#define SCALE 2

//structure of 1 tile 
typedef struct Tile
{
	SDL_Rect tileRect; //rectangle which has the tile
	int id ; //identifier for display
}Tile;

//structure of the map
typedef struct Map
{
	Tile *tiles; //has an array of tiles
	int nbtiles_x, nbtiles_y; //number of tiles in x of the tileset, and in y
	int max_x_map, max_y_map; //number of tiles in x of the map, and in y
	int width_tile,height_tile; //width and height of a tile, calculated from the width and height of the tileset (dynamically)
}Map;


void LoadMapTiles(Map *map);
void DisplayMap(FILE *fileLevel, SDL_Texture *tileset, Map *map, SDL_Manager *sdlManager);
#endif
