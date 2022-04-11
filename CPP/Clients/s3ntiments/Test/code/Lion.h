#ifndef Lion_h
#define Lion_h

#include "Animal.h"
#include "Jumper.h"

class Lion : public Animal, public Jumper
{
public:
	virtual char getLabel();
	virtual bool isMoveValid(Board* board, int x, int y);
	

	Lion(COLOR color, int X, int Y);
};

#endif
