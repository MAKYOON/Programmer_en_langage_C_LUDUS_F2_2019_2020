#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "vect3.h"
#include "gameObject.h"
#include "dblList.h"

#define TAILLE 100

int main()
{
	DoubleLinkedList *dblList = malloc(sizeof(*dblList));
	GameObject gameObject1;
	GameObject gameObject2;
	GameObject gameObject3;
	GameObject gameObject4;
	GameObject gameObject5;
	GameObject gameObject6;

	gameObject1.key = 1;
	gameObject2.key = 2;
	gameObject3.key = 3;
	gameObject4.key = 4;
	gameObject5.key = 5;
	gameObject6.key = 6;


	InitialiseDblList(dblList);

	PushFirstList(dblList, gameObject1);
	//liste output expected : 1
	PushFirstList(dblList, gameObject2);
	//liste output expected : 2 1
	PushFirstList(dblList, gameObject3);
	//liste output expected : 3 2 1
	PushLastList(dblList,gameObject4);
	//liste output expected : 3 2 1 4
	PushBeforeList(dblList,gameObject5,4);
	//liste output expected : 3 2 1 5 4
	PushAfterList(dblList,gameObject6,3);
	//liste output expected : 3 2 1 6 5 4

	//test for list output
	Element *elementTemp = dblList->first;
	printf("Apres ajout, la liste doublement chainee contient : \n");
	for (int i = 0; i < dblList->size; i++)
	{
		printf("%d ", elementTemp->gameObject.key );
		elementTemp = elementTemp->next;
	}

	RemoveList(dblList,1);
	//liste output expected : 2 1 6 5 4
	RemoveList(dblList,dblList->size);
	//liste output expected : 2 1 6 5
	RemoveList(dblList,2);
	//liste output expected : 2 6 5
	printf("\n");
	elementTemp = dblList->first;
	printf("Apres les retraits, la liste doublement chainee contient : \n");
	for (int i = 0; i < dblList->size; i++)
	{
		printf("%d ", elementTemp->gameObject.key );
		elementTemp = elementTemp->next;
	}

	free(elementTemp);

	return 0;
}


