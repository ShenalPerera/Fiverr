#ifndef Human_H
#define Human_H
#include "Player.h"

class Human : public Player {
	public:
		Human(char* name, COLOR color);

		virtual void make_Move(Board* board);
};


#endif
