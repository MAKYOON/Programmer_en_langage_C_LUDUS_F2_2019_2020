#include "ball.h"
#include "game.h"

//function that draws the ball point by point according to its current center
void DrawBall(Ball ball, SDL_Renderer *pRenderer)
{
	for (ball.y = -ball.r; ball.y <= ball.r; ball.y++)
	{
		for(ball.x = -ball.r; ball.x <= ball.r; ball.x++)
		{
			if(ball.x*ball.x+ball.y*ball.y <= ball.r*ball.r)
				SDL_RenderDrawPoint(pRenderer,ball.xc+ball.x,ball.yc+ball.y);
		}
	}
}

//reset the ball after a goal, give it a random position
//takes an integer right as parameter, we will put 1 if it needs to start going right (if the player 2 scored a goal) or -1 if we want it to go left (if player 1 scored a goal)
//also reset paddle position
void Goal(Ball *ball, int right, SDL_Rect *rectPad1, SDL_Rect *rectPad2)
{
    ball->xc = BALL_INITIAL_X;
    ball->yc = BALL_INITIAL_Y;
    ball->xspeed = right * BALL_SPEED;
    ball->yspeed = (rand()%BALL_SPEED*2+1) - BALL_SPEED;
    while (ball->yspeed == 0)
        ball->yspeed = (rand()%BALL_SPEED*2+1) - BALL_SPEED;
    rectPad1->x = 0;
    rectPad1->y = (WINDOW_HEIGHT/2)-(PADDLE_HEIGHT/2);
    rectPad2->x = WINDOW_WIDTH-PADDLE_WIDTH;
    rectPad2->y = (WINDOW_HEIGHT/2)-(PADDLE_HEIGHT/2);
}

//this function will check whether the ball hit the walls, the paddle or there is a goal
void CheckCollision(Ball *ball, SDL_Rect *rectPad1, SDL_Rect *rectPad2, int *scorep1, int *scorep2)
{
    srand(time(NULL));
	if(ball->yc - ball->r <= 0)
    {
        //if it collided with the top border
        ball->yspeed = -ball->yspeed;
    }
    else if(ball->yc-ball->r >= WINDOW_HEIGHT - ball->r)
    {
        //if it collided with the bottom border
        ball->yspeed = -ball->yspeed;
    }
    //if it collided with the left paddle : we check if at the next frame, the x of the center of the ball will be <= to the paddle
    //and we also check that the y of the center is between the height of the paddle, if both conditions are met then we hit the left paddle
    else if ((ball->xc-ball->r+ball->xspeed <= PADDLE_WIDTH) && (ball->yc+ball->yspeed >= rectPad1->y) && (ball->yc+ball->yspeed <= rectPad1->y + PADDLE_HEIGHT))
    {
        //we invert the x speed so it goes the other way and we speed it
        ball->xspeed = -ball->xspeed +1;
        //if it hits the superior part of the paddle then it should go up
        if (ball->yc+ball->yspeed > rectPad1->y && ball->yc + ball->yspeed < rectPad1->y + PADDLE_HEIGHT/2)
        {
            if (ball->yspeed > 0)
                ball->yspeed = -ball->yspeed;
        }
        //same for bottom
        else
        {
            if (ball->yspeed < 0)
                ball->yspeed = -ball->yspeed;
        }

    }
    //Same for right paddle
    else if ((ball->xc-ball->r+ball->xspeed >= WINDOW_WIDTH - ball->r - PADDLE_WIDTH) && (ball->yc+ball->yspeed >=rectPad2->y) && (ball->yc+ball->yspeed <= rectPad2->y + PADDLE_HEIGHT))
    {
        ball->xspeed = -ball->xspeed - 1;

        if (ball->yc+ball->yspeed > rectPad2->y && ball->yc + ball->yspeed < rectPad2->y + PADDLE_HEIGHT/2)
        {
            if (ball->yspeed > 0)
                ball->yspeed = -ball->yspeed;
        }
        else
        {
            if (ball->yspeed < 0)
                ball->yspeed = -ball->yspeed;
        }
    }
    //if the ball is out of the screen to the left side
    else if (ball->xc-ball->r+ball->xspeed < PADDLE_WIDTH)
    {
        //increment score for player 2, reset ball, and give it a random speed/angle
        *scorep2 += 1;
        Goal(ball,-1,rectPad1,rectPad2);

    }
    //out but to the right side
    else if (ball->xc-ball->r+ball->xspeed > WINDOW_WIDTH - PADDLE_WIDTH)
    {
        *scorep1 += 1;
        Goal(ball,1,rectPad1,rectPad2);
    }
}






