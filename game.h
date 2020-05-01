#ifndef GAME_H
#define GAME_H
#include "sdl.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

#define PADDLE_WIDTH 25
#define PADDLE_HEIGHT 100
#define PADDLE_SPEED 20
#define BUFFER 1000
#define TRUE 1
#define FALSE 0
#define BALL_SPEED 6
#define BALL_INITIAL_X WINDOW_WIDTH/2
#define BALL_INITIAL_Y WINDOW_HEIGHT/2
#define SCORE_WIDTH 30
#define SCORE_HEIGHT 30
#define FPS_MAX 60

extern SDL_Texture *LoadPaddle(char *player, SDL_Renderer *pRenderer);
extern void DrawMiddleLine(SDL_Renderer *pRenderer);
extern void HandleInput(SDL_Event event, int *quit, SDL_Rect *rectPad1, SDL_Rect *rectPad2);
extern void UpdateScore(TTF_Font *font, int scorep1, int scorep2, SDL_Rect rectScore1, SDL_Rect rectScore2,SDL_Renderer *pRenderer);


#endif
