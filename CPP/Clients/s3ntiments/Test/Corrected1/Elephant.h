#ifndef Elephant

#include "Animal.h"

class Elephant : public Animal{
public:
	virtual char getLabel();
	virtual bool isMoveValid(Board* board, int x, int y);

	Elephant(COLOR color, int X, int Y);
};

#endif
