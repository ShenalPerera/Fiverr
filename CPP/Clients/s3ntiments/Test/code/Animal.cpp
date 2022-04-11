#include<bits/stdc++.h>
#include "Animal.h"
#include "Player.h"
#include "Game.h"

using namespace std;

Animal::Animal(COLOR color, int X, int Y) : color(color), X(X), Y(Y), Trap(false), River(false), Den(false) {};

void Animal::setName(string inputname) {
	this->name = inputname;
}

void Animal::setRank(int inputrank) {
	this->rank = inputrank;
}

void Animal::setX(int inputX) {
	this->X = inputX;
}
void Animal::setY(int inputY) {
	this->Y = inputY;
}

void Animal::setisTrap(bool istrap) {
	this->Trap = istrap;
}

void Animal::setisRiver(bool isriver) {
	this->River = isriver;
}
void Animal::isDen(bool den) {
	this->Den = den;
}

void Animal::setColor(COLOR inputcolor) {
	this->color = inputcolor;
}


string Animal::getName() {
	return this->name;
}

int Animal::getRank() {
	return this->rank;
}

int Animal::getX() {
	return this->X;
}
int Animal::getY() {
	return this->Y;
}
bool Animal::getisTrap() {
	return this->Trap;
}
bool Animal::getisRiver() {
	return this->River;
}
bool Animal::getisDen() {
	return this->Den;
}
COLOR Animal::getColor() {
    return this->color;
}

//char Animal::getLabel() {
//	char animalname = getName().at(0);
//	if (getName() == "LEOPARD") {
//		animalname = 'P';
//	}
//	if (getcolor() == BLUE) {
//		tolower(animalname);
//	return animalname;
//}

bool Animal::isOpponent(Animal* piece) {
	if (getColor() != piece->getColor()) {
		return true;
	}
	
	return false;
}

bool Animal::canEat(Animal* rank) {
	if (getisTrap()) {
		return false;
	}
	
	if (rank == EMPTY) {
		return false;
	}

	if (getRank() > rank->getRank()) {
		return true;
	}

	return false;
}


void Animal::Eat(Board* board, Animal* piece) {
	if (canEat(piece)) {
		int x1 = this->getX();
		int y1 = this->getY();
	}

	Player* player = board->getGame()->get_Player(COLOR (1 - (int)(board->getGame()->get_Player->getTurn())));

	board->putPiece(piece->getX(), piece->getY(), this);
	board->putPiece(x1, y1, EMPTY);
	cout << " The " << piece->getName() << " of " << player->get_Name() << " is captured! ";
	player->remove_Pieces(piece);

}




void Animal::MovePiece(Board* board, int x, int y) {
	int x1 = this->getX();
	int y1 = this->getY();

	Animal* piece = board->getPiece(x, y);

	if (isMoveValid(board, x, y)) {
		if (canEat(piece) {
			Eat(board, piece);
		}

		else if (isMoveValid(board, x, y)) {
			board->putPiece(x, y, this);
			board->putPiece(x1, y1, EMPTY);
		}
	}

	if (board->isTrap(x, y, COLOR(1-(int)getcolor()))) {
		setRank(0);
		setisTrap(true);
	}
	else {
		int rank;

		switch (tolower(getLabel())) {
			case 'r' : 
				rank = 1;
				break;
			case 'c': 
				rank = 2;
				break;
			case 'd':
				rank = 3;
				break;
			case 'w':
				rank = 4;
				break;
			case 'p':
				rank = 5;
				break;
			case 't':
				rank = 6;
				break;
			case 'l':
				rank = 7;
				break;
			case 'e':
				rank = 8;
				break;
		}

		setRank(rank);
		setisTrap(false);
	}

	if (board->isDen(x, y, COLOR(1 - (int)getcolor())) || (board->getGame()->getPlayer(COLOR(1 - (int)getcolor())->countPieces() == 0))) {
		board->getGame()->setState(GAME_OVER);
	}

}

bool Animal::isMoveValid(Board* board, int x, int y) {
	Animal* piece = board->getPiece(x, y);

	if (isOpponent(piece) && !canEat(piece)) {
		return false;
	}
	if (board->isRiver(x, y)) {
		return false;
	}
	if (board->isDen(x, y, getcolor())) {
		return false;
	}
	return true;
}