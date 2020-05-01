#include "ball.h"
#include "game.h"


int main(int argc, char* argv[])
{
	
	SDL_Manager SDLManager;

	SDLManager.pWindow=NULL; //Pointeur typedef SDL_Window possède la référence d'un window(Win32)
	SDLManager.pRenderer=NULL; //Pointeur typedef SDL_RENDERER possède la référence du rendu encapsulé dans Window
	SDL_Event event;

    int scorep1 = 0;
    int scorep2 = 0;
    unsigned int deltaTime = 0;
    unsigned int currentTime = 0;

    //this is to give the ball a random direction at the beginning
    int initial_y_angle = (rand()%BALL_SPEED*2+1) - BALL_SPEED;
    while (initial_y_angle == 0)
            initial_y_angle = (rand()%BALL_SPEED*2+1) - BALL_SPEED;
    //creating the ball
	Ball ball = {0,0,BALL_INITIAL_X,BALL_INITIAL_Y,10,BALL_SPEED,initial_y_angle};

	//this variable is used for the main loop
	int quit = FALSE;
	//Initialization of SDL
	int error = InitAllSDL(&SDLManager.pWindow, &SDLManager.pRenderer);
	if (error != 0)
	{
	    //font to write score
        TTF_Font *font = TTF_OpenFont("comic.ttf", 15);
		//Loading paddles
		SDL_Texture *paddle1 = LoadPaddle("1",SDLManager.pRenderer);
		SDL_Texture *paddle2 = LoadPaddle("2",SDLManager.pRenderer);

		//paddle position
		SDL_Rect rectPad1 = {0,(WINDOW_HEIGHT/2)-(PADDLE_HEIGHT/2),PADDLE_WIDTH,PADDLE_HEIGHT};
		SDL_Rect rectPad2 = {WINDOW_WIDTH-PADDLE_WIDTH,(WINDOW_HEIGHT/2)-(PADDLE_HEIGHT/2),PADDLE_WIDTH,PADDLE_HEIGHT};
		//position of scores
		SDL_Rect rectScore1 = {WINDOW_WIDTH/4, 50,SCORE_WIDTH,SCORE_HEIGHT};
		SDL_Rect rectScore2 = {WINDOW_WIDTH/4*3, 50,SCORE_WIDTH,SCORE_HEIGHT};

        //gameloop
		while(quit != TRUE)
		{
		    //limiting FPS, this way we have a movement based on time and not on framerate
		    currentTime = SDL_GetTicks();
		    if (currentTime - deltaTime > 1000/FPS_MAX)
            {
                //black background color
                SDL_SetRenderDrawColor(SDLManager.pRenderer,0,0,0,SDL_ALPHA_OPAQUE);
                SDL_RenderClear(SDLManager.pRenderer);
                //function that draws the middle line
                DrawMiddleLine(SDLManager.pRenderer);
                //Draw the ball
                CheckCollision(&ball,&rectPad1,&rectPad2,&scorep1,&scorep2);
                //moving ball
                ball.xc += ball.xspeed;
                ball.yc += ball.yspeed;
                //drawing the ball
                DrawBall(ball,SDLManager.pRenderer);
                //handle the input to move the paddles
                HandleInput(event,&quit,&rectPad1,&rectPad2);
                UpdateScore(font,scorep1,scorep2,rectScore1,rectScore2,SDLManager.pRenderer);
                deltaTime = currentTime;
            }
            else
            {
                SDL_Delay(1000/FPS_MAX - (deltaTime - currentTime));
            }

			//modify the position of the paddles
			SDL_RenderCopy(SDLManager.pRenderer,paddle1,NULL,&rectPad1);
			SDL_RenderCopy(SDLManager.pRenderer,paddle2,NULL,&rectPad2);
			//update the renderer
			SDL_RenderPresent(SDLManager.pRenderer);
		}

        //we quit/destroy everything
        TTF_CloseFont(font);
        QuitEverything(&paddle1,&paddle2,&SDLManager.pWindow,&SDLManager.pRenderer);
	}
	else
	{
		return 0;
	}


	return 0;



}
