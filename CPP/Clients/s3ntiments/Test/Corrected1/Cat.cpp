#include "Cat.h"
#include "Animal.h"

using namespace std;

Cat::Cat(COLOR color, int X, int Y) : Animal(color, X, Y)
{
	setName(animalNames[1]);
	setRank(CAT);
}

char Cat::getLabel() {
	if (getcolor() == BLUE) {
		return 'c';
	}
	
	return 'C';
	
}

bool Cat::isMoveValid(Board* board, int x, int y) {
	if (abs(getX() - x) + abs(getY() - y) != 1) {
		return false;
	}
	return Animal::isMoveValid(board, x, y);
}

