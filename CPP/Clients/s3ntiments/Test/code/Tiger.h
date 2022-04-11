#ifndef Tiger_H
#define Tiger_H

#include "Animal.h"
#include "Jumper.h"

class Tiger : public Animal, public Jumper
{
public:
	virtual char getLabel();
	virtual bool isMoveValid(Board* board, int x, int y);


	Tiger(COLOR color, int X, int Y);
};

#endif#
