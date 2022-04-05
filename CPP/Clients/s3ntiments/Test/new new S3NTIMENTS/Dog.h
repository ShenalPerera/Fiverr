#ifndef Dog

#include "Animal.h"

class Dog : public Animal
{
	virtual char getLabel();
	virtual bool isMoveValid(Board* board, int x, int y);

	Dog(COLOR color, int X, int Y);
};

#endif
