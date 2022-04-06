#include"Jumper.h"
#include"Animal.h"

using namespace std;

Jumper::Jumper() {};

bool Jumper::canJump(Board* board, Animal* piece, int x2, int y2, int steps) {
	Animal* pieces = board->getPiece(x2, y2);

	int currX = piece->getX();
	int currY = piece->getY();
	
	for (int i = 0; i < steps; ++i) {
		if (x2 - currX == 0) {
			if (board->getPiece(x2, i + 1) != (Animal*)EMPTY) {
				if (board->getPiece(x2, i + 1)->getRank() == RAT) {
					return false;
				}
			}
			if (y2 - currY == 0) {
				if (board->getPiece(i + 1, y2) != (Animal*)EMPTY) {
					if (board->getPiece(x2, i + 1)->getRank() == RAT) {
						return false;
					}

				}
			}
		}
	}

	if (abs(y2 - currY) == steps && x2-currX == 0) {
		return true;
	}
	if (abs(x2 - currX) == steps && y2 - currY == 0) {
		return true;
	}

	if (pieces == (Animal*)EMPTY) {
		return true;
	}

}