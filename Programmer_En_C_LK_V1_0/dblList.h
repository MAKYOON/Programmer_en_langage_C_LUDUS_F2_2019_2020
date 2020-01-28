#ifndef DBLLIST_H_DEFINED
#define DBLLIST_H_DEFINED

#include "gameObject.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Element
{
	GameObject gameObject;
	struct Element* next;
	struct Element* prev;
}Element;

typedef struct DoubleLinkedList
{
	Element* first;
	Element* last;
	int size;
}DoubleLinkedList;

extern void InitialiseDblList(DoubleLinkedList *dblList);
extern void PushFirstList(DoubleLinkedList *dblList, GameObject gameObjectToAdd);
extern void PushLastList(DoubleLinkedList *dblList, GameObject gameObjectToAdd);
extern void PushBeforeList(DoubleLinkedList *dblList, GameObject gameObject, int index);
extern void PushAfterList(DoubleLinkedList *dblList, GameObject gameObjectToAdd, int index);
extern void RemoveList(DoubleLinkedList *dblList, int index);
extern void EmptyList(DoubleLinkedList *dblList);
extern void DisplayList(DoubleLinkedList *dblList);

#endif // DBLLIST_H_DEFINED
