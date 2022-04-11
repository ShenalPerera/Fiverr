#ifndef Wolf_H
#define Wolf_H

#include "Animal.h"

class Wolf : public Animal
{
public:
	virtual char getLabel();
	virtual bool isMoveValid(Board* board, int x, int y);

	Wolf(COLOR color, int X, int Y);
};

#endif
