#ifndef Cat

#include "Animal.h"

class Cat : public Animal
{
	virtual char getLabel();
	virtual bool isMoveValid(Board* board, int x, int y);

	Cat(COLOR color, int X, int Y);
};

#endif