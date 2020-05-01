#include "game.h"


//function that returns the texture of the paddle by searching its png
SDL_Texture *LoadPaddle(char *player, SDL_Renderer *pRenderer)
{
	char imageName[BUFFER] = "Paddle";
	strcat(imageName,player);
	SDL_Surface *sur_paddle = IMG_Load(strcat(imageName,".png"));
	SDL_Texture *paddle = SDL_CreateTextureFromSurface(pRenderer,sur_paddle);
	SDL_FreeSurface(sur_paddle);

	return paddle;
}

void DrawMiddleLine(SDL_Renderer *pRenderer)
{
    SDL_SetRenderDrawColor(pRenderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(pRenderer,WINDOW_WIDTH/2,0,WINDOW_WIDTH/2,WINDOW_HEIGHT);
}

void HandleInput(SDL_Event event, int *quit, SDL_Rect *rectPad1, SDL_Rect *rectPad2)
{
	const Uint8 *keyStates = SDL_GetKeyboardState(NULL);

	if(SDL_PollEvent(&event))
    {
		switch(event.type)
		{
			case SDL_QUIT:
			{
				*quit = TRUE;
				break;
			}
			case SDL_KEYDOWN:
			{
				if (keyStates[SDL_SCANCODE_W])
				{
					if (rectPad1->y > 0)
                    {
                        if (rectPad1->y - PADDLE_SPEED < 0)
                            rectPad1->y = 0;
                        else
                            rectPad1->y -= PADDLE_SPEED;
                    }
				}
				if (keyStates[SDL_SCANCODE_S])
				{
					if (rectPad1->y < WINDOW_HEIGHT-PADDLE_HEIGHT)
                    {
                        if (rectPad1->y + PADDLE_SPEED > WINDOW_HEIGHT-PADDLE_HEIGHT)
                            rectPad1->y = WINDOW_HEIGHT-PADDLE_HEIGHT;
                        else
                            rectPad1->y += PADDLE_SPEED;
                    }
				}
				if (keyStates[SDL_SCANCODE_UP])
				{
                    if (rectPad2->y > 0)
                    {
                        if (rectPad2->y - PADDLE_SPEED < 0)
                            rectPad2->y = 0;
                        else
                            rectPad2->y -= PADDLE_SPEED;
                    }
				}
				if (keyStates[SDL_SCANCODE_DOWN])
				{
				    if (rectPad2->y < WINDOW_HEIGHT-PADDLE_HEIGHT)
                    {
                        if (rectPad2->y + PADDLE_SPEED > WINDOW_HEIGHT-PADDLE_HEIGHT)
                            rectPad2->y = WINDOW_HEIGHT-PADDLE_HEIGHT;
                        else
                            rectPad2->y += PADDLE_SPEED;
                    }
				}
				if (keyStates[SDL_SCANCODE_ESCAPE])
		    		*quit = TRUE;
                break;
			}
		}
    }
}

void UpdateScore(TTF_Font *font, int scorep1, int scorep2, SDL_Rect rectScore1, SDL_Rect rectScore2,SDL_Renderer *pRenderer)
{
    SDL_Color textColor = {255,255,255};
    char *c_scorep1 = (char*)malloc(sizeof(scorep1));
    sprintf(c_scorep1,"%d",scorep1);
    char *c_scorep2 = (char*)malloc(sizeof(scorep2));
    sprintf(c_scorep2,"%d",scorep2);
    SDL_Surface *score1temp = TTF_RenderText_Solid(font, c_scorep1, textColor);
    SDL_Surface *score2temp = TTF_RenderText_Solid(font, c_scorep2, textColor);

    SDL_Texture *score1 = SDL_CreateTextureFromSurface(pRenderer,score1temp);
    SDL_Texture *score2 = SDL_CreateTextureFromSurface(pRenderer,score2temp);
    SDL_FreeSurface(score1temp);
    SDL_FreeSurface(score2temp);

    SDL_RenderCopy(pRenderer,score1, NULL, &rectScore1);
    SDL_RenderCopy(pRenderer,score2, NULL, &rectScore2);
    SDL_DestroyTexture(score1);
    SDL_DestroyTexture(score2);
}
