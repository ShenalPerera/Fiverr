#ifndef Rat

#include "Animal.h"

class Rat : public Animal
{
	virtual char getLabel();
	virtual bool isMoveValid(Board* board, int x, int y);
	virtual bool canEat(Animal* rank);

	Rat(COLOR color, int X, int Y);
};

#endif
