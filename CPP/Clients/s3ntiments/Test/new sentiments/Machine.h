#ifndef Machine
#include "Player.h"

class Machine : public Player {
public:
	Machine(char* name, COLOR color);

	virtual void make_Move(Board* board);
};

#endif
