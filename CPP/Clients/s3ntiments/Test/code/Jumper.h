#ifndef Jumper_H
#define Jumper_H
#include "Animal.h"

class Jumper {
	public:
		Jumper();
		bool canJump(Board* board, Animal* animal, int x2, int y2, int steps);

}



#endif
