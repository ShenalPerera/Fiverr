#include "Rat.h"
#include "Animal.h"

using namespace std;

Rat::Rat(COLOR color, int X, int Y) : Animal(color, X, Y)
{
	setName(animalNames[RAT - 1]);
	setRank(RAT);
}

char Rat::getLabel() {
	if (getcolor() == BLUE) {
		return 'r';
	}

	return 'R';

}

bool Rat::isMoveValid(Board* board, int x, int y) {
	Animal* p = board->getPiece(x, y);
	
	if (abs(getX() - x) + abs(getY() - y) != 1) {
		return false;
	}
	else if (isOpponent(p) && canEat(p)) {
		if (board->isRiver(x, y) != board->isRiver(getX(), getY())) {
			return false;
		}
		return true;
	}
	else {
		if (p == (Animal*)EMPTY || p == (Animal*)TRAP) {
			return true;
		}
		return false;
	}
}

bool Rat::canEat(Animal* rank) {
	if (getisTrap()) {
		return false;
	}
	else if (rank == (Animal*)EMPTY) {
		return false;
	}
	else if(rank->getRank() == ELEPHANT || rank->getRank() <= this->getRank()) {
		return true;
	}

	return false;

}