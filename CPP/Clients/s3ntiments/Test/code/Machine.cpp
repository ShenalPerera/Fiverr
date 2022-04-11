#include "Machine.h"
#include <iostream>
#include <time.h>
#include "Game.h"
#include "Player.h"
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
			
			Animal* piece = (board->getGame()->get_Player(COLOR(board->getGame()->get_Turn()))->get_Piece(0));

			if (toupper(piece->getLabel()) == 'R') {
				board->getGame()->set_State(GAME_OVER);

				board->getGame()->set_Turn(COLOR(1 - (int)(piece->getColor())));
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
			board->getGame()->set_Turn(COLOR(1 - (int)(piece->getColor())));
			break;
		}
	}

	board->MovePiece(x1, y1, x2, y2);



}