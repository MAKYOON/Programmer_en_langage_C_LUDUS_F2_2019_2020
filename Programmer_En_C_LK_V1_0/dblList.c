#include "dblList.h"


void InitialiseDblList(DoubleLinkedList *dblList)
{
	dblList->first = NULL;
	dblList->last = NULL;
	dblList->size = 0;
}

void PushFirstList(DoubleLinkedList *dblList, GameObject gameObjectToAdd)
{
	Element *newElement = malloc(sizeof(*newElement));
	if ((dblList == NULL) | (newElement == NULL))
		exit(EXIT_FAILURE);

	newElement->gameObject = gameObjectToAdd;

	if (dblList->first == NULL)
	{

		dblList->first = newElement;
		dblList->last = newElement;
		newElement->next = NULL;
		newElement->prev = NULL;
	}
	else
	{
		newElement->next = dblList->first;
		newElement->prev = NULL;
		dblList->first->prev = newElement;
		dblList->first = newElement;
	}
	dblList->size++;
}

void PushLastList(DoubleLinkedList *dblList, GameObject gameObjectToAdd)
{
	Element *newElement = malloc(sizeof(*newElement));
	if ((dblList == NULL) | (newElement == NULL))
		exit(EXIT_FAILURE);

	newElement->gameObject = gameObjectToAdd;

	if (dblList->first == NULL)
	{
		dblList->first = newElement;
		dblList->last = newElement;
		newElement->next = NULL;
		newElement->prev = NULL;
	}
	else
	{
		newElement->next = NULL;
		newElement->prev = dblList->last;
		dblList->last->next = newElement;
		dblList->last = newElement;
	}
	dblList->size++;
}

void PushBeforeList(DoubleLinkedList *dblList, GameObject gameObjectToAdd, int index)
{
	if (dblList != NULL)
	{
		Element *elementTemp = dblList->first;
		for (int i = 0; i < index-1; i++)
		{
			elementTemp = elementTemp->next;
		}

		Element *newElement = malloc(sizeof(*newElement));
		if (newElement != NULL)
		{
			newElement->gameObject = gameObjectToAdd;
			newElement->next = elementTemp;
			newElement->prev = elementTemp->prev;
			elementTemp->prev->next = newElement;
			elementTemp->prev = newElement;

		}
	}
	dblList->size++;
}


void PushAfterList(DoubleLinkedList *dblList, GameObject gameObjectToAdd, int index)
{
	if (dblList != NULL)
	{
		Element *elementTemp = dblList->first;
		for (int i = 0; i < index-1; i++)
		{
			elementTemp = elementTemp->next;
		}

		Element *newElement = malloc(sizeof(*newElement));
		if (newElement != NULL)
		{
			newElement->gameObject = gameObjectToAdd;
			newElement->next = elementTemp->next;
			newElement->prev = elementTemp;
			elementTemp->next->prev = newElement;
			elementTemp->next = newElement;

		}
	}
	dblList->size++;
}

void RemoveList(DoubleLinkedList *dblList, int index)
{
	if (dblList != NULL)
	{
		Element *elementTemp = dblList->first;
		for (int i = 0; i < index-1; i++)
		{
			elementTemp = elementTemp->next;
		}

		//if it's the first element
		if (elementTemp->prev == NULL)
		{
			dblList->first = elementTemp->next;
			elementTemp->next->prev = NULL;
		}
		//else if it's the last element
		else if (elementTemp->next == NULL)
		{
			dblList->last = elementTemp->prev;
			elementTemp->prev->next = NULL;
		}
		//else it's in the middle of the list
		else
		{
			elementTemp->prev->next = elementTemp->next;
			elementTemp->next->prev = elementTemp->prev;	
		}

		free(elementTemp);
		dblList->size--;
	}
}