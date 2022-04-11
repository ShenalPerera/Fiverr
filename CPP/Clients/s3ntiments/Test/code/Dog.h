#ifndef Dog_H
#define Dog_H
#include "Animal.h"

class Dog : public Animal
{
public:
	virtual char getLabel();
	virtual bool isMoveValid(Board* board, int x, int y);

	Dog(COLOR color, int X, int Y);
};

#endif
