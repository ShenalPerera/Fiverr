#include "Wolf.h"
#include "Animal.h"

using namespace std;

Wolf::Wolf(COLOR color, int X, int Y) : Animal(color, X, Y)
{
	setName(animalNames[LEOPARD - 1]);
	setRank(LEOPARD);
}

char Wolf::getLabel() {
	if (getColor() == BLUE) {
		return 'w';
	}

	return 'W';

}

bool Wolf::isMoveValid(Board* board, int x, int y) {
	if (abs(getX() - x) + abs(getY() - y) != 1) {
		return false;
	}
	return Animal::isMoveValid(board, x, y);
}