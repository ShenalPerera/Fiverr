#include "Leopard.h"
#include "Animal.h"

using namespace std;

Leopard::Leopard(COLOR color, int X, int Y) : Animal(color, X, Y)
{
	setName(animalNames[LEOPARD - 1]);
	setRank(LEOPARD);
}

char Leopard::getLabel() {
	if (getcolor() == BLUE) {
		return 'p';
	}

	return 'P';

}

bool Leopard::isMoveValid(Board* board, int x, int y) {
	if (abs(getX() - x) + abs(getY() - y) != 1) {
		return false;
	}
	return Animal::isMoveValid(board, x, y);
}
