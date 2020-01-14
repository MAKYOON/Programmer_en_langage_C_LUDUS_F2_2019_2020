#include "input.h"


//converts the char input by user into an int for ship placement/shot
int CharToInt(char c_userInput)
{
	switch (c_userInput)
	{
		case 'A': return 1;
		break;
		case 'B': return 2;
		break;
		case 'C': return 3;
		break;
		case 'D': return 4;
		break;
		case 'E': return 5;
		break;
		case 'F': return 6;
		break;
		case 'G': return 7;
		break;
		case 'H': return 8;
		break;
		case 'I': return 9;
		break;
		case 'J': return 10;
		break;
	}
	return 0;
}

//we check if the letter input is between A and J
//returns the letter if yes, else returns \0
char isValidCharInput(char c_userInput)
{
	if (c_userInput < 'A' || c_userInput > 'J')
		return 0;
	else
		return c_userInput;
}

//we check if the input is between 1 and 10
//returns the user input for number between 1 and 9 if yes or 10, else returns 0

int isValidIntInput(char c_userInput[LENGTH_INPUT])
{

	if (c_userInput[1] == '\0')
	{
		if ((c_userInput[0] - 1) >= '0' && (c_userInput[0] - 1) <= '9')
			return (int)c_userInput[0]-'0';
		else
			return 0;
	}
	else
	{
		if (c_userInput[0] == '1' && c_userInput[1] == '0')
			return 10;
		else
			return 0;
	}
}
