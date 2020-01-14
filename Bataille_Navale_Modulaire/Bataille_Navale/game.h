#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <windows.h>
#include "map.h"
#include "ship.h"
#include "score.h"



#define SIZE 10
#define SIZE_PSEUDO 25

void color(int t,int f);
void SetPseudo(char c_pseudo_p1[SIZE_PSEUDO],char c_pseudo_p2[SIZE_PSEUDO]);
void PlayerTurn(char c_pseudo_player[SIZE_PSEUDO], char c_playermap[SIZE][SIZE], char c_playershootingmap[SIZE][SIZE], char c_adversarymap[SIZE][SIZE], int n_adversary_copymap[SIZE][SIZE], int* n_score_player);
void EndOfTurn(int* n_playerturn);
void Game();
void DisplayEndOfGame(char c_pseudo_player[SIZE_PSEUDO], int n_scoreplayer, int n_turns);
#endif // GAME_H_INCLUDED
