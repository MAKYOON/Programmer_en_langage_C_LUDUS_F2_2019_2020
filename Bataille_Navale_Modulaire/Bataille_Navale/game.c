#include "game.h"



//function to color text
void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}


void SetPseudo(char c_pseudo_p1[SIZE_PSEUDO],char c_pseudo_p2[SIZE_PSEUDO])
{
	printf("Joueur 1, choisissez votre pseudo\n");
	scanf("%s",c_pseudo_p1);
	fflush(stdin);
	printf("Joueur 2, choisissez votre pseudo\n");
	scanf("%s",c_pseudo_p2);
	system("cls");
	fflush(stdin);
}

//function that handles a player's turn : shows his ships and all the shots he made
void PlayerTurn(char c_pseudo_player[SIZE_PSEUDO], char c_playermap[SIZE][SIZE], char c_playershootingmap[SIZE][SIZE], char c_adversarymap[SIZE][SIZE], int n_adversary_copymap[SIZE][SIZE], int* n_score_player)
{
	system("cls");
	printf("%s\n", c_pseudo_player);
	printf("Votre score : %d\n", *n_score_player);
	printf("Vos tirs :\n");
	AfficheMap(c_playershootingmap);
	printf("\n");
	printf("O = tir rate\n");
	printf("X = tir touche\n");
	printf("Vos bateaux :\n");
	printf("\n");
	AfficheMap(c_playermap);
	printf("\n");
	printf("Appuyez sur Entree pour passer a la phase de tir\n");
	fflush(stdin);
	getchar();
	system("cls");
	Shoot(c_playershootingmap,c_adversarymap,n_adversary_copymap,n_score_player);
	printf("\n");
	printf("Resultat des tirs\n");
	AfficheMap(c_playershootingmap);
}

//this function is called when the current player ends his turn
void EndOfTurn(int* n_playerturn)
{
	printf("\n");
	printf("Appuyez sur entree et ensuite passez l'ordinateur a l'autre joueur\n");
	fflush(stdin);
	getchar();
	system("cls");
	printf("Appuyez sur entree pour continuer\n");
	fflush(stdin);
	getchar();
	if (*n_playerturn == 1)
		*n_playerturn = 2;
	else
		*n_playerturn = 1;
}


//main loop of the game
void Game()
{
	char c_p1[SIZE][SIZE];
	char c_shoot_p1[SIZE][SIZE];
	int n_p1[SIZE][SIZE];
	int n_score_p1=0;
	char c_pseudo_p1[SIZE_PSEUDO];

	char c_p2[SIZE][SIZE];
	char c_shoot_p2[SIZE][SIZE];
	int n_p2[SIZE][SIZE];
	int n_score_p2=0;
	char c_pseudo_p2[SIZE_PSEUDO];

	int n_playerturn = 1;
	int n_gameisplaying = 1;
	int n_turns = 0;

	InitialiseMaps(c_p1,c_p2,c_shoot_p1,c_shoot_p2,n_p1,n_p2);
	SetPseudo(c_pseudo_p1,c_pseudo_p2);

	printf("%s, vous allez placer vos bateaux\n",c_pseudo_p1);
	printf("Appuyez sur entree pour continuer\n");
	getchar();
	CreateFleet(c_p1,n_p1);
	printf("Creation de la flotte terminee\n");

	system("cls");
	printf("%s, vous allez placer vos bateaux\n",c_pseudo_p2);
	getchar();
	CreateFleet(c_p2,n_p2);
	printf("Creation de la flotte terminee\n");

	while (n_gameisplaying)
	{
		if (n_playerturn == 1)
		{
			PlayerTurn(c_pseudo_p1,c_p1,c_shoot_p1,c_p2,n_p2,&n_score_p1);
			n_turns++;
			if (hasShipLeft(n_p2))
			{
				EndOfTurn(&n_playerturn);
			}
			else
			{
				DisplayEndOfGame(c_pseudo_p1,n_score_p1,n_turns);
				n_gameisplaying = 0;
			}
		}
		else
		{
			PlayerTurn(c_pseudo_p2,c_p2,c_shoot_p2,c_p1,n_p1,&n_score_p2);
			if (hasShipLeft(n_p1))
			{
				EndOfTurn(&n_playerturn);
			}
			else
			{
				DisplayEndOfGame(c_pseudo_p2,n_score_p2,n_turns);
				n_gameisplaying = 0;
			}
		}
	}
	fflush(stdin);
	getchar();
}

//displays the win screen : score, number of turns, final score (the faster the player ends, the better)
void DisplayEndOfGame(char c_pseudo_player[SIZE_PSEUDO], int n_scoreplayer, int n_turns)
{
	int n_finalscore;
	char c_registerscore[100];

	printf("\n");
	printf("%s, vous avez gagne !\n", c_pseudo_player);
	printf("Vous avez %d points\n", n_scoreplayer);
	printf("Il s'est ecoule %d tours\n",n_turns);
	n_finalscore = (n_scoreplayer/n_turns)*100;
	printf("Votre total de points est donc : %d \n", n_finalscore);
	//function that stores into the first argument (a pointer, here our char array) the string passed as 2nd argument, allowing us to concatenate
	sprintf(c_registerscore,"Gagnant : %s - Points : %d - Nombre de tours : %d", c_pseudo_player, n_finalscore, n_turns);
	RegisterScore(c_registerscore);

}

