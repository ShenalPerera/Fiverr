#include "Human.h"
#include "Game.h"
#include <iostream>
#include <limits>

using namespace std;

Human::Human(char* name, COLOR color) : Player(name, color) {};

void Human::make_Move(Board* board) {
	while (true) {
		cout << get_Name() << "'s Turn: ";
		char c1, c2; int x1, x2; cin >> c1 >> x1 >> c2 >> x2;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter valid inputs ";
			continue;
		}

		if (c1 == 'Z' && c2 == 'Z' && x1 == 0 && x2 == 0) {
			board->getGame()->set_State(GAME_OVER);

			board->getGame()->set_Turn(COLOR(1 - (board->getGame()->get_Turn())));
			return;
		}

		int r1 = x1 - 1;
		int r2 = x2 - 1;

		int y1 = c1 - 'A';
		int y2 = c2 - 'A';

		bool validMove = board->MovePiece(r1, y1, r2, y2);
		if (validMove) {
			break;
		}
		cout << "Not a valid move, try again! ";

	}
}
