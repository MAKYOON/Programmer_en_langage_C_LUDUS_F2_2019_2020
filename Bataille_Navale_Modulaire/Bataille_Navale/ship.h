#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED
#include "map.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>



#define TORPILLEUR 2
#define SOUS_MARIN 3
#define CONTRE_TORPILLEUR 3
#define CROISEUR 4
#define PORTE_AVIONS 5
#define NB_BATEAUX 5
#define SIZE 10

void CreateFleet(char c_player[SIZE][SIZE], int n_player_copymap[SIZE][SIZE]);
int CanPlaceShip(int n_shiptype, int n_x, int n_y, int n_horizontal, char c_map[][SIZE]);
void PlaceShip(int n_shiptype, int n_x, int n_y, int n_horizontal, char c_map[SIZE][SIZE], int n_map[SIZE][SIZE]);
int ShipExists(int n_arr_ships[], int n_choix);
int isShipDestroyed(int n_typeofship_hit, int n_map[SIZE][SIZE]);
void Shoot(char c_playershootingmap[SIZE][SIZE],char c_adversarymap[SIZE][SIZE], int n_adversary_copymap[SIZE][SIZE], int* n_score_player);
int CanShoot(int n_x, int n_y, char c_shotmap[SIZE][SIZE]);
int hasShipLeft(int n_adversary_copymap[SIZE][SIZE]);

#endif // SHIP_H_INCLUDED

