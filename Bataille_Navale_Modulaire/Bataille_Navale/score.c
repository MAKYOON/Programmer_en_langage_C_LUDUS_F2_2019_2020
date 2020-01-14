#include "score.h"

//function that registers the score into a binary file
void RegisterScore(char c_registerscore[SIZE_REGISTERED_SCORE])
{
	FILE *binaryfile=NULL;

	if ((binaryfile = fopen("scores.bin","ab")) == NULL)
	{
		printf("Erreur dans l'ouverture du fichier binaire\n");
	}
	else
	{
		fwrite(c_registerscore,sizeof(char)*SIZE_REGISTERED_SCORE,1,binaryfile);
	}

	fclose(binaryfile);
}

//function that reads the binary file to display the registered score
void DisplayScore()
{
	FILE *binaryfile=NULL;
	char c_scoreplayer[SIZE_REGISTERED_SCORE];

	if ((binaryfile = fopen("scores.bin","rb")) == NULL)
	{
		printf("Erreur dans l'ouverture du fichier binaire\n");
	}
	else
	{
		printf("Voici les scores actuels enregistres :\n");
		printf("\n");
		while(fread(c_scoreplayer,sizeof(char)*SIZE_REGISTERED_SCORE,1,binaryfile)&&!feof(binaryfile))//Lecture dans le fichier en mode binaire
		{
            printf("%s\n",c_scoreplayer);
		}

	}
}

