#include "Machine.h"
#include "Game.h"
#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

Machine::Machine(char* name, COLOR color) : Player(name, color) {
	srand(time(0));
};


void Machine::make_Move(Board* board) {
	
	int index = rand() % this->count_Pieces();
	
	Animal* piece = this->get_Piece(index);

	int x1 = piece->getX();
	int y1 = piece->getY();
	int x2;
	int y2;
	int iteration = 0;

	while (true) {
		
		if (board->getGame()->get_Player(COLOR(board->getGame()->get_Turn()))->count_Pieces() == 1) {
			
			Animal* piece2 = board->getGame()->get_Player(COLOR(board->getGame()->get_Turn()))->get_Piece(0);

			if (toupper(piece2->getLabel()) == 'R') {
				board->getGame()->set_State(GAME_OVER);

				board->getGame()->set_Turn(COLOR(1 - (int)(piece2->getcolor())));
				break;
			}
		}

		x2 = x1 + (pow(-1, rand())) * (rand() % 2);
		y2 = y1 + (pow(-1, rand())) * (rand() % 2);

		if (board->isMoveValid(x1, y1, x2, y2)) {
			break;
		}

		if (toupper(piece->getLabel()) == 'T' || toupper(piece->getLabel()) == 'L') {
			x2 = x1 + (pow(-1, rand())) * (rand() % 3);
			y2 = y1 + (pow(-1, rand())) * (rand() % 3);
			if (board->isMoveValid(x1, y1, x2, y2)) {
				break;
			}

			x2 = x1 + (pow(-1, rand())) * (rand() % 2);
			y2 = y1 + (pow(-1, rand())) * (rand() % 2);
			if (board->isMoveValid(x1, y1, x2, y2)) {
				break;
			}
		}

		iteration++;

		if (iteration > 2000) {
			board->getGame()->set_State(GAME_OVER);
			board->getGame()->set_Turn(COLOR(1 - (int)(board->getGame()->get_Turn())));
			break;
		}
	}

	board->MovePiece(x1, y1, x2, y2);



}