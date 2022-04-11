#include "Dog.h"
#include "Animal.h"

using namespace std;

Dog::Dog(COLOR color, int X, int Y) : Animal(color, X, Y)
{
	setName(animalNames[DOG-1]);
	setRank(DOG);
}

char Dog::getLabel() {
	if (getColor() == BLUE) {
		return 'd';
	}

	return 'D';

}

bool Dog::isMoveValid(Board* board, int x, int y) {
	if (abs(getX() - x) + abs(getY() - y) != 1) {
		return false;
	}
	return Animal::isMoveValid(board, x, y);
}
