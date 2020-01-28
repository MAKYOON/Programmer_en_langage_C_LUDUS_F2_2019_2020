#include "dblList.h"

//initialize first/last pointer to NULL and 0 for the size
void InitialiseDblList(DoubleLinkedList *dblList)
{
	dblList->first = NULL;
	dblList->last = NULL;
	dblList->size = 0;
}

//this function pushes an element and it becomes the first element of the list
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


//this function pushes an element and it becomes the last element of the list
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

//this function takes into parameter an index, and pushes an element BEFORE the index of the element indicated
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

//this function takes into parameter an index, and pushes an element AFTER the index of the element indicated
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

//this function takes into parameter an index, and REMOVES the element AT the index indicated
void RemoveList(DoubleLinkedList *dblList, int index)
{
	if (dblList != NULL)
	{
		Element *elementTemp = dblList->first;
		for (int i = 0; i < index-1; i++)
		{
			elementTemp = elementTemp->next;
		}
		//if there's only 1 element we just have to free the element
		if (dblList->size == 1)
		{
			free(elementTemp);
		}
		else //else there's pointer to affect
		{
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
		}

		dblList->size--;
	}
}

//freeing all elements then the list
void EmptyList(DoubleLinkedList *dblList)
{
	while (dblList->size > 0)
	{
		RemoveList(dblList,1);
	}
	free(dblList);
}