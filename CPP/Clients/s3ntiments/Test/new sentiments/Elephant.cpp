#include "Elephant.h"
#include "Animal.h"

using namespace std;

Elephant::Elephant(COLOR color, int X, int Y) : Animal(color, X, Y)
{
	setName(animalNames[ELEPHANT - 1]);
	setRank(ELEPHANT);
}

char Elephant::getLabel() {
	if (getcolor() == BLUE) {
		return 'e';
	}

	return 'E';

}

bool Elephant::isMoveValid(Board* board, int x, int y) {
	if (abs(getX() - x) + abs(getY() - y) != 1) {
		return false;
	}
	return Animal::isMoveValid(board, x, y);
}
