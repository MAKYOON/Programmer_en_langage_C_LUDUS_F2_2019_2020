#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAILLE 100



//type structuré récursif ou auto-référentiel (pointeur qui pointe sur lui-même)

//il existe plusieurs catégories de chaînage : lorsque la structure contient une ou des données et un pointeur vers la structure suivante, on parle
//de liste chaînée.

//lorsque la structure contient une ou des données, un pointeur vers la structure suivante et un pointeur vers la structure précédente, on parle
//de liste doublement chaînées.

//lorsque la structure contient une ou des données, un pointeur vers une première structure suivante et un pointeur vers une seconde structure, on
//parle d'arbre binaire

//PILE LIFO

typedef struct ElementPile
{
	int nombre;
	struct ElementPile *suivant; 
}ElementPile;

typedef struct Pile
{
	ElementPile *premier;
	int size;
}Pile;

//FILE FIFO

typedef struct ElementFile
{
	int nombre;
	struct ElementFile *suivant;
}ElementFile;

typedef struct File
{
	ElementFile *premier;
	int size;
}File;



void affichePile(Pile *pile);
void InitialisePile(Pile *pile);
void empiler(Pile *pile, int n_nb);
int depiler(Pile *pile);

void InitialiseFile(File *file);
void enfiler(File *file, int nvNombre);
int defiler(File *file);
void afficheFile(File *file);


int main ()
{
	Pile *pile = malloc(sizeof(*Pile));
	if (pile == NULL)
		exit(EXIT_FAILURE);
	InitialisePile(pile);
	empiler(pile,3);
	empiler(pile,6);
	empiler(pile,9);
	empiler(pile,12);
	empiler(pile,15);
	empiler(pile,18);
	empiler(pile,21);
	printf("Voici la pile a l'etat initial :\n");
	affichePile(pile);

	while (pile->size != 0)
	{
		printf("Je depile : %d\n",depiler(pile));
		printf("La taille de la pile est : %d\n", pile->size );
	}

	printf("______________________\n");

	File *file = malloc(sizeof(*File));
		if (file == NULL)
			exit(EXIT_FAILURE);
	InitialiseFile(file);
	enfiler(file,3);
	enfiler(file,6);
	enfiler(file,9);
	enfiler(file,12);
	enfiler(file,15);
	enfiler(file,18);
	enfiler(file,21);
	printf("Voici la file a l'etat initial : \n");
	afficheFile(file);

	while (file->size != 0)
	{
		printf("Je defile : %d\n",defiler(file));
		printf("La taille de la file est : %d\n", file->size );
	}

	free(pile);
	free(file);

	return 0;
}

//FONCTIONS POUR LA PILE

void InitialisePile(Pile *pile)
{
	pile -> premier = NULL;
	pile -> size = 0;
}

void empiler(Pile *pile, int n_nb)
{
	ElementPile *elementAEmpiler = malloc(sizeof(*ElementPile));
	if (pile == NULL && elementAEmpiler == NULL)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		elementAEmpiler -> nombre = n_nb;
		elementAEmpiler -> suivant = pile -> premier;
		pile -> premier = elementAEmpiler;
		pile -> size++;
	}

}

int depiler(Pile *pile)
{
	int nombredepile = 0;
	ElementPile *elementADepiler = pile -> premier;

	if (pile != NULL && elementADepiler != NULL)
	{
		nombredepile = elementADepiler -> nombre;
		pile -> premier = elementADepiler -> suivant;
		free(elementADepiler);
		pile -> size--;
		return nombredepile;
	}
	else
		return 0;


}

void affichePile(Pile *pile)
{
	if (pile == NULL)
	{
		exit(EXIT_FAILURE);
	}

	ElementPile *actuel = pile -> premier;
	while (actuel != NULL)
	{
		printf("%d\n", actuel->nombre );
		actuel = actuel -> suivant;
	}

}

//FONCTIONS POUR LA FILE

void InitialiseFile(File *file)
{
	file -> premier = NULL;
	file -> size = 0;
}

void enfiler(File *file, int nvNombre)
{
	ElementFile *nouveau = malloc(sizeof(*nouveau));
	if (file == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}

	nouveau->nombre = nvNombre;
	nouveau->suivant = NULL;

	if (file->premier != NULL) /* La file n'est pas vide */
	{
		/* On se positionne à la fin de la file */
		ElementFile *elementActuel = file->premier;
		while (elementActuel->suivant != NULL)
		{
			elementActuel = elementActuel->suivant;
		}
		elementActuel->suivant = nouveau;
	}
	else /* La file est vide, notre élément est le premier */
	{
		file->premier = nouveau;
	}
	file -> size++;
}

int defiler(File *file)
{
	if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

	int nombreDefile = 0;

	/* On vérifie s'il y a quelque chose à défiler */
	if (file->premier != NULL)
	{
		ElementFile *elementDefile = file->premier;

		nombreDefile = elementDefile->nombre;
		file->premier = elementDefile->suivant;
		free(elementDefile);
		file -> size--;
	}

	return nombreDefile;
}

void afficheFile(File *file)
{
	if (file == NULL)
		exit(EXIT_FAILURE);

	ElementFile *elementActuel = file -> premier;

	while (elementActuel != NULL)
	{
		printf("%d\n", elementActuel -> nombre );
		elementActuel = elementActuel -> suivant;
	}
}