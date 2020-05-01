#ifndef BALL_H
#define BALL_H
#include <SDL2/SDL.h>

typedef struct Ball
{
	int x; //x coordinate of 1 point
	int y; //y coordinate of 1 point
	int xc; // x center of the circle
	int yc;// y center of the circle
	int r; //Radius of circle
	int xspeed;
	int yspeed;
}Ball;

extern void DrawBall(Ball ball, SDL_Renderer *pRenderer);
extern void CheckCollision(Ball *ball, SDL_Rect *rectPad1, SDL_Rect *rectPad2, int *scorep1, int *scorep2);
extern void Goal(Ball *ball, int right, SDL_Rect *rectPad1, SDL_Rect *rectPad2);

#endif
