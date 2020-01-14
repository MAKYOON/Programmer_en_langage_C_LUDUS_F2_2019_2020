#include "map.h"



//initialise all the maps
//we use char arrays for visual and the int arrays are for the boat destruction verification
//also we have a map of shots for each player
void InitialiseMaps(char c_p1[SIZE][SIZE], char c_p2[SIZE][SIZE], char c_shoot_p1[SIZE][SIZE],char c_shoot_p2[SIZE][SIZE],int n_p1[SIZE][SIZE], int n_p2[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			c_p1[i][j] = '_';
			c_p2[i][j] = '_';
			c_shoot_p1[i][j] = '_';
			c_shoot_p2[i][j] = '_';
			n_p1[i][j] = 0;
			n_p2[i][j] = 0;
		}
	}
}


//function to display map
void AfficheMap(char c_map[SIZE][SIZE])
{
	printf("      A   B   C   D   E   F   G   H   I   J\n");
	int number = 1;
	for (int i = 0; i < SIZE; i++)
	{
		printf("%-3d", number);
		for (int j = 0; j < SIZE; j++)
		{
			if (c_map[j][i] == 'X')
				color(12,0); //we set the X in red just for visual
			else
				color(15,0);

			printf(" %3c",c_map[j][i]);

		}
		printf("\n");
		number++;
	}
}
