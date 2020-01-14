#include <stdlib.h>
#include <windows.h>
#include "define.h"

void Menu();

int main()
{
	Menu();

	return 0;
}

void Menu()
{
	int choix;
	do
	{
		printf("Appuyez sur 1 pour jouer\nAppuyez sur 2 pour voir le classement\nAppuyez sur 3 pour quitter\n");
		scanf("%d",&choix);
		fflush(stdin);
	} while (choix < 1 || choix > 3);
	switch (choix)
	{
		case 1: system("cls"); //clear screen
				Game();
		break;
		case 2: DisplayScore();
		break;
		case 3: exit(0);
		break;
	}
}




