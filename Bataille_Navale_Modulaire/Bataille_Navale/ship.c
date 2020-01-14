#include "ship.h"


//function that checks if the ship asked by the user exists (or is already placed)
//it is used to make sure the player doesnt place twice the same ship
//returns 1 if it exists, 0 if it doesn't
//basically it is an array with the values {1,2,3,4,5}
//when the player places a ship, it changes this value to 0 : {0,2,3,4,5}
int ShipExists(int n_arr_ships[NB_BATEAUX], int n_choix)
{
	for (int i = 0; i < NB_BATEAUX; i++)
	{
		if (n_choix == n_arr_ships[i])
		{
			n_arr_ships[i] = 0;
			return 1;
		}
	}
	return 0;

}

//function to place a ship, it takes into parameter :
//n_shiptype which goes from 1 to 5 (user input) and with a switch case we know which ship the player chose
//n_x and n_y are coordinates for placement
//n_horizontal works like a boolean, 1 for horizontal and 0 for vertical
//it takes the char array to place 'U' where the ship is
//and also the int array and its going to place the n_shiptype variable (if the player picks 1, its going to place 1 where the ship is placed)
void PlaceShip(int n_shiptype, int n_x, int n_y, int n_horizontal, char c_map[SIZE][SIZE], int n_map[SIZE][SIZE])
{
	int n_ship = n_shiptype;
	//we get the length of the ship input by the user
	//they are defined at the top, but basically they have the int values of cells they take
	switch (n_shiptype)
	{
		case 1: n_shiptype = TORPILLEUR;
		break;
		case 2: n_shiptype = SOUS_MARIN;
		break;
		case 3: n_shiptype = CONTRE_TORPILLEUR;
		break;
		case 4: n_shiptype = CROISEUR;
		break;
		case 5: n_shiptype = PORTE_AVIONS;
		break;
	}
	//since we asked the user input between 1-10 we need to substract 1 in order to stay within array range
	n_x -= 1;
	n_y -= 1;

	for (int i = 0; i < n_shiptype; i++)
	{
		if (n_horizontal)
		{
			c_map[n_x+i][n_y] = 'U';
			n_map[n_x+i][n_y] = n_ship;
		}
		else
		{
			c_map[n_x][n_y+i] = 'U';
			n_map[n_x][n_y+i] = n_ship;
		}
	}
}

//function that checks if we can place a ship, whether if it exceeds array length or if the user tries to place a ship onto an existing one
//takes n_shiptype into parameter to know which ship the player chose, aswell as n_x and n_y coordinates and the horizontal or vertical placement
//then it calculates the length of the ship and sees if its already taken, or going out of range
//returns 1 if we can place a ship, 0 if we can't
int CanPlaceShip(int n_shiptype, int n_x, int n_y, int n_horizontal, char c_map[SIZE][SIZE])
{
	switch (n_shiptype)
	{
		case 1: n_shiptype = TORPILLEUR;
		break;
		case 2: n_shiptype = SOUS_MARIN;
		break;
		case 3: n_shiptype = CONTRE_TORPILLEUR;
		break;
		case 4: n_shiptype = CROISEUR;
		break;
		case 5: n_shiptype = PORTE_AVIONS;
		break;
	}
	n_x -= 1;
	n_y -= 1;

	if (n_horizontal)
	{
		//this checks that for the length of the ship, if there's already a ship then we return 0 (we cant place the ship here)
		for (int i = 0; i < n_shiptype; i++)
		{
			if (c_map[n_x+i][n_y] == 'U')
				return 0;
		}
		//this checks that we stay within the map range
		if ((n_x <= SIZE - n_shiptype))
			return 1;
		else
			return 0;
	}
	else
	{
		for (int i = 0; i < n_shiptype; i++)
		{
			if (c_map[n_x][n_y+i] == 'U')
				return 0;
		}
		if ((n_y <= SIZE - n_shiptype))
			return 1;
		else
			return 0;
	}
}

//function that creates the whole fleet for a player (5 ships)
//uses CanPlaceShip(), PlaceShip() and ShipExists() functions
//so we just ask to the user : the type of ship he wants to place (we check if its not already placed), x and y coordinates, vertical/horizontal placement
//we check if its valid, then we place it if so
void CreateFleet(char c_player[SIZE][SIZE], int n_player_copymap[SIZE][SIZE])
{
	int n_arr_ships[NB_BATEAUX];
	int n_x;
	int n_y;
	int n_shiptype;
	int n_horizontal;
	int n_nbbateaux = 1; //we set it to 1 in order to display which ship we are currently placing
	char c_userInput[LENGTH_INPUT]; //for the letter input

	for (int i = 0; i <= NB_BATEAUX; i++)
	{
		n_arr_ships[i] = i+1;
	}
	//NB_BATEAUX = 5
	//the while loop works while we havent placed all the ships
	while (n_nbbateaux != NB_BATEAUX +1)
	{
		//we get the type of ship that the user wants to place
		do
		{
			system("cls");
			AfficheMap(c_player);
			printf("\n");
			printf("Placement du bateau numero %d\n", n_nbbateaux);
			printf("Veuillez selectionner votre bateau\n");
			printf("Tapez 1 pour le torpilleur (2 cases)\n");
			printf("Tapez 2 pour le sous marin (3 cases)\n");
			printf("Tapez 3 pour le contre torpilleur (3 cases)\n");
			printf("Tapez 4 pour le croiseur (4 cases)\n");
			printf("Tapez 5 pour le porte avions (5 cases)\n");
			scanf("%c",c_userInput);
			fflush(stdin);
		} while (!ShipExists(n_arr_ships,(int)c_userInput[0]-'0'));
		n_shiptype = (int)c_userInput[0]-'0';

		do
		{
			//we get the x coordinates
			do
			{
				printf("Veuillez rentrer les coordonnees x de l'arriere de votre bateau (entre A et J)\n");
				scanf("%c",c_userInput);
				fflush(stdin);
				printf("\n");
			} while (!isValidCharInput(c_userInput[0]));
			n_x = CharToInt(c_userInput[0]);

			//we get the y coordinates
			do
			{
				printf("Veuillez rentrer les coordonnees y de l'arriere de votre bateau (entre 1 et 10)\n");
				scanf("%s",c_userInput);
				fflush(stdin);
				printf("\n");
			} while (!isValidIntInput(c_userInput));
			n_y = isValidIntInput(c_userInput);

			//we get 1 if the user wants horizontal placement, 0 if vertical
			do
			{
				printf("Voulez vous le placer horizontalement(1) ou verticalement(0)? Horizontal = vers la droite, Vertical = vers le bas\n");
				scanf("%c",c_userInput);
				fflush(stdin);
				printf("\n");
			} while (c_userInput[0] != '1' && c_userInput[0] != '0');
			n_horizontal = (int)c_userInput[0] - '0';

		} while (!CanPlaceShip(n_shiptype,n_x,n_y,n_horizontal,c_player)); //and we keep asking till we can place the ship with the user input
		//then we place the ship and display the map to the player
		PlaceShip(n_shiptype,n_x,n_y,n_horizontal,c_player,n_player_copymap);
		n_nbbateaux++;
	}
	printf("Voici le placement de vos bateaux\n");
	AfficheMap(c_player);
	printf("\n");
	printf("Appuyez sur entree pour continuer\n");
	getchar();
	fflush(stdin);
}



//function that checks if we can shoot at the x and y given
//basically making sure we dont shoot at the same place twice
int CanShoot(int n_x, int n_y, char c_playershootingmap[SIZE][SIZE])
{
	n_x -=1;
	n_y -=1;

	if (c_playershootingmap[n_x][n_y] == '_')
		return 1;
	else
		return 0;
}

//function that checks if we destroyed a ship
//it is called if we hit a ship, then we check in the int array if there are still some cells with the same index
//if there aren't any left, it means it is destroyed so we return the type of ship destroyed (ranging from 1 to 5) else we return 0
//ex : we hit a ship with the index 1, we check if there are any other "1" on the int array, if there is it's still alive, if not : destroyed!
int isShipDestroyed(int n_typeofship_hit, int n_map[SIZE][SIZE])
{
	int n_tempcells=0;

 	for (int i = 0; i < SIZE; i++)
 	{
 		for (int j = 0; j < SIZE; j++)
 		{
 			if (n_map[i][j] == n_typeofship_hit)
 			{
 				n_tempcells++;
 			}
 		}
 	}

 	if (n_tempcells == 0)
 		return n_typeofship_hit;
 	else
 		return 0;
}

//function that handles the shooting
//it takes into parameter the map of shots of the player currently shooting (to call the CanShoot() function and make sure we dont shoot at the same place twice)
//it also takes the map of the player shot at (the char array) to check if we hit or miss
//it also needs the int array of the player shot at in order to call the function isShipDestroyed()
//and the pointer to the score of the player to modify its value
void Shoot(char c_playershootingmap[SIZE][SIZE],char c_adversarymap[SIZE][SIZE], int n_adversary_copymap[SIZE][SIZE], int* n_score_player)
{
	char c_userInput[LENGTH_INPUT];
	int n_x, n_y;
	int n_typeofship_hit=0;
	int n_tempverif=0;
	AfficheMap(c_playershootingmap);
	do
	{
		do
		{
			printf("Veuillez rentrer les coordonnees x de votre tir (entre A et J)\n");
			scanf("%c",c_userInput);
			fflush(stdin);
			printf("\n");
		} while (!isValidCharInput(c_userInput[0]));
		n_x = CharToInt(c_userInput[0]);

		do
		{
			printf("Veuillez rentrer les coordonnees y de votre tir (entre 1 et 10)\n");
			scanf("%s",c_userInput);
			fflush(stdin);
			printf("\n");
		} while (!isValidIntInput(c_userInput));
		n_y = isValidIntInput(c_userInput);

	} while (!CanShoot(n_x,n_y,c_playershootingmap));

	n_x -= 1;
	n_y -= 1;
	//if he misses then we just display the miss symbol
	if (c_adversarymap[n_x][n_y] == '_')
	{
		c_playershootingmap[n_x][n_y] = 'O';
		printf("\n");
		printf("Rate !\n");
		printf("Vous obtenez 0 points\n");
	}
	else //else he hit
	{
		//we add some score
		*n_score_player += 100;
		printf("\n");
		printf("Touche !\n");
		printf("Vous obtenez 100 points\n");
		//so we put the visual 'X'
		c_playershootingmap[n_x][n_y] = 'X';
		c_adversarymap[n_x][n_y] = 'X';
		//we get the type of ship hit and we check if its destroyed or not
		n_typeofship_hit = n_adversary_copymap[n_x][n_y];
		n_adversary_copymap[n_x][n_y] = 0;
		n_tempverif = isShipDestroyed(n_typeofship_hit,n_adversary_copymap);
		//if it is, we printf the type of ship that was destroyed
		if (n_tempverif)
		{
			switch (n_tempverif)
			{
				case 1: printf("\n");
						printf("Coule !\n");
						printf("Vous avez detruit le TORPILLEUR\n");
						printf("Vous obtenez 1000 points\n");
						*n_score_player += 1000;
				break;
				case 2: printf("\n");
						printf("Coule !\n");
				 		printf("Vous avez detruit le SOUS MARIN\n");
						*n_score_player += 2000;
						printf("Vous obtenez 2000 points\n");
				break;
				case 3: printf("\n");
						printf("Coule !\n");
						printf("Vous avez detruit le CONTRE TORPILLEUR\n");
						*n_score_player += 2000;
						printf("Vous obtenez 2000 points\n");
				break;
				case 4: printf("\n");
						printf("Coule !\n");
						printf("Vous avez detruit le CROISEUR\n");
						*n_score_player += 3000;
						printf("Vous obtenez 3000 points\n");
				break;
				case 5:	printf("\n");
						printf("Coule !\n");
						printf("Vous avez detruit le PORTE AVIONS\n");
						*n_score_player += 4000;
						printf("Vous obtenez 4000 points\n");
				break;
			}
		}
	}
}

//function that checks if someone won by checking if the int array of the adversary has only 0
//returns 1 if there are ships left, 0 if not
int hasShipLeft(int n_adversary_copymap[SIZE][SIZE])
{
	int n_stillalive=0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j= 0; j < SIZE; j++)
		{
			if (n_adversary_copymap[i][j] != 0)
				n_stillalive++;
		}
	}

	if (n_stillalive)
		return 1;
	else
		return 0;
}
