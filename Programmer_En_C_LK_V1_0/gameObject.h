#ifndef GAMEOBJECT_H_DEFINED
#define GAMEOBJECT_H_DEFINED

#include "vect3.h"

typedef struct GameObject
{
	int key;
	char* mesh;
	Vect3 pos;
}GameObject;
#endif // GAMEOBJECT_H_DEFINED

