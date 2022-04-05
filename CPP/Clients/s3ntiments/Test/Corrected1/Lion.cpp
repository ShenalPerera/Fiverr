#include "Lion.h"
#include <bits/stdc++.h>

using namespace std;

Lion::Lion(COLOR color, int X, int Y) : Animal(color, X, Y) {
	setName(animalNames[LION-1]);
	setRank(LION);
}

char Lion::getLabel() {
	if (getcolor() == BLUE) {
		return 'l';
	}
	else {
		return 'L';
	}
}

bool Lion::isMoveValid(Board* board, int X, int Y) {
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
