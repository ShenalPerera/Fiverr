#include<bits/stdc++.h>
#include "Board.h"
#include "Game.h"
#include "Animal.h"
#include "Lion.h"
#include "Tiger.h"
#include "Rat.h"
#include "Elephant.h"
#include "Leopard.h"
#include "Wolf.h"
#include "Dog.h"
#include "Cat.h"

using namespace std;

bool Board::isEmpty(int x, int y) {
	if (arr[x][y] == (Animal*)EMPTY) {
		return true;
	}
	return false;
}

bool Board::isTrap(int x, int y, COLOR color) {
	if (y == 2 || y == 4) {
		if (x == 0 && color == BLUE) {
			return true;
		}
		else if (x == 8 && color == RED) {
			return true;
		}
	}
	if (y == 3) {
		if (x == 1 && color == BLUE) {
			return true;
		}
		else if (x == 7 && color == RED) {
			return true;
		}
	}
	return false;
}

bool Board::isRiver(int x, int y) {
	if (x >= 3 && x <= 5) {
		if (y >= 1 && y <= 2) {
			return true;
		}
		else if (y >= 4 && y <= 5) {
			return true;
		}
	}
	return false;
}

bool Board::isDen(int x, int y, COLOR color) {
	if (y == 3) {
		if (x == 0 && color == BLUE) {
			return true;
		}
		else if (x == 8 && color == RED) {
			return true;
		}
	}
	return false;
}


Animal* Board::getPiece(int x, int y) {
	if ((x > height-1 || y > width-1) || (x < 0 || y < 0)) {
		return (Animal*)OUTBOUNDS;
	}
	return arr[x][y];
}

void Board::setPiece(int x, int y, Animal* piece) {
	arr[x][y] = piece;
	if (piece != (Animal*)EMPTY) {
		piece->setX(x);
		piece->setY(y);
	}
}

bool Board::isMoveValid(int x1, int y1, int x2, int y2) {
	if (this->getPiece(x1, y1) == (Animal*)EMPTY || x1 == x2 && y1 == y2 || this->getPiece(x2, y2) == (Animal*)OUTBOUNDS) {
		return false;
	}

	if (!(x1 == x2 && y1 != y2) || (y1 == y2 && x1 != x2)) {
		return false;
	}

	if (getGame()->get_Turn() != this->getPiece(x1, y1)->getColor()) {
		return false;
	}

	Animal* piece = this->getPiece(x1, x2);
	if (!(piece->isMoveValid(this, x2, y2))) {
		return false;
	}

	return true;

}

bool Board::MovePiece(int x1, int y1, int x2, int y2) {
	if (isMoveValid(x1, y1, x2, y1)) {
		getPiece(x1, y1)->MovePiece(this, x2, y2);
		return true;
	}
	return false;
}

Game* Board::getGame() const {
	return this->game;
}

void Board::drawBoard() {
		cout << "    A   B   C   D   E   F   G\n";
		cout << "   +---+---+---+---+---+---+\n";
		for (int i = 0; i < height; ++i) {
			cout << i + 1 << " ";
			for (int j = 0; j < width; ++j) {
				if (isDen(i, j, (COLOR)BLUE) || isDen(i, j, (COLOR)RED)) {
					
					if (arr[i][j] == (Animal*)EMPTY || isDen(i, j, (COLOR)BLUE) || isDen(i, j, (COLOR)RED)) {
						cout << "| X ";
					}	
					else {
						cout << "| " << arr[i][j]->getLabel() << " ";
					}
				}
				else if (isTrap(i, j, (COLOR)BLUE) || isTrap(i, j, (COLOR)RED)) {
					if (arr[i][j] == (Animal*)EMPTY || isTrap(i, j, (COLOR)BLUE) || isTrap(i, j, (COLOR)RED)) {
						cout << "| # ";
					}
					else {
						cout << "| " << arr[i][j]->getLabel() << " ";
					}
				}
				else if (isRiver(i, j)) {
					if (isRiver(i, j)) {
						cout << "| * ";
					}
					else {
						cout << "| r ";
					}
				}
				else if (isEmpty(i, j)) {
					cout << "|  ";
				}
				else {
					cout << "| " << arr[i][j]->getLabel() << " ";
				}

			}
			cout << "|" << endl;
			cout << "   +---+---+---+---+---+---+\n";
		}

}

void Board::initBoard() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			arr[i][j] = (Animal*)EMPTY;

			COLOR color = (COLOR)(i < 4 ? BLUE : RED);

			if (i == 0 && j == 0 || i == height - 1 && j == width - 1) {
				arr[i][j] = new Lion(color, i, j);
			}
			if (i == 0 && j == width - 1 || i == height - 1 && j == 0) {
				arr[i][j] = new Tiger(color, i, j);
			}
			if (i == 1 && j == 1 || i == height - 2 && j == width - 2) {
				arr[i][j] = new Dog(color, i, j);
			}
			if (i == 1 && j == width - 2 || i == height - 2 && j == 1) {
				arr[i][j] = new Cat(color, i, j);
			}
			if (i == 2 && j == 0 || i == height - 3 && j == width - 1) {
				arr[i][j] = new Rat(color, i, j);
			}
			if (i == 2 && j == 4 || i == 6 && j == 2) {
				arr[i][j] = new Wolf(color, i, j);
			}
			if (i == 2 && j == 2 || i == 6 && j == 4) {
				arr[i][j] = new Leopard(color, i, j);
			}
			if (i == 2 && j == 6 || i == 6 && j == 0) {
				arr[i][j] = new Elephant(color, i, j);
			}
			if (i == 3 || i == 4 || i == 5) {
				if (j % 3 != 0) {
					arr[i][j] = (Animal*)RIVER;
				}
			}
			if (i == 0 && j == 3 || i == 8 && j == 3) {
				arr[i][j] = (Animal*)DEN;
			}
			if (i == 0 || i == 8) {
				if (j == 2 || j == 4) {
					arr[i][j] = (Animal*)TRAP;
				}
			}
			if (i == 1 && j == 3 || i == 7 && j == 3) {
				arr[i][j] = (Animal*)TRAP;
			}
			if (arr[i][j] != (Animal*)EMPTY) {
				game->get_Player(color)->add_Pieces(arr[i][j]);
			}
		}
	}
}