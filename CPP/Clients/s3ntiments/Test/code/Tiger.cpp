#include "Tiger.h"
#include <bits/stdc++.h>

using namespace std;

Tiger::Tiger(COLOR color, int X, int Y) : Animal(color, X, Y) {
	setName(animalNames[TIGER - 1]);
	setRank(TIGER);
}

char Tiger::getLabel() {
	if (getColor() == BLUE) {
		return 't';
	}
	else {
		return 'T';
	}
}

bool Tiger::isMoveValid(Board* board, int X, int Y) {
	int xpos = this->getX();
	int ypos = this->getY();

	if (abs(xpos - X) + abs(ypos - Y) > 1) {
		if (canJump(board, this, X, Y, 2) || canJump(board, this, X, Y, 3)) {
			return true;
		}
		else {
			return false;
		}
	}

	return Animal::isMoveValid(board, X, Y);
}