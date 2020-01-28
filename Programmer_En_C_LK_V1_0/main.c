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
	printf("Pushing '1' to 1st position : \n");
	DisplayList(dblList);

	PushFirstList(dblList, gameObject2);
	//liste output expected : 2 1
	printf("Pushing '2' to 1st position \n");
	DisplayList(dblList);

	PushFirstList(dblList, gameObject3);
	//liste output expected : 3 2 1
	printf("Pushing '3' to 1st position \n");
	DisplayList(dblList);
	
	PushLastList(dblList,gameObject4);
	printf("Pushing '4' to last position \n");
	DisplayList(dblList);
	//liste output expected : 3 2 1 4

	PushBeforeList(dblList,gameObject5,4);
	printf("Pushing '5' BEFORE the 4th number \n");
	DisplayList(dblList);
	//liste output expected : 3 2 1 5 4

	PushAfterList(dblList,gameObject6,3);
	printf("Pushing '6' AFTER the 3rd number  \n");
	DisplayList(dblList);
	//liste output expected : 3 2 1 6 5 4

	printf("Removing the number at position 1\n");
	RemoveList(dblList,1);
	DisplayList(dblList);
	//liste output expected : 2 1 6 5 4
	printf("Removing the number at last position\n");
	RemoveList(dblList,dblList->size);
	DisplayList(dblList);
	//liste output expected : 2 1 6 5

	printf("Removing the number at position 2\n");
	RemoveList(dblList,2);
	DisplayList(dblList);
	//liste output expected : 2 6 5
	
	printf("\n");
	printf("Emptying list now...\n");
	EmptyList(dblList);
	printf("...List is now empty\n");

	return 0;
}


