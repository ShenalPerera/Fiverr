#include <iostream>
#include "Game.h"
#include "Machine.h"
#include "Human.h"

using namespace std;

Game::Game(MODES mode, char* gamelog) : state(RUN) {
	Player* blue = (Player*)(mode == HVH) ? (Player*)new Machine("BLUE", BLUE) : new Human("BLUE", BLUE);

	Player* red = (Player*)(mode == MVM) ? (Player*)new Human("RED", RED) : new Machine("RED", RED);

	player[0] = blue;
	player[1] = red;

	turn = BLUE;
	
	board = new Board(this, gamelog);
}

Player* Game::get_Player(COLOR color) {
	return player[(int)color];
}

COLOR Game::get_Turn() {
	return turn;
}

CONDITIONS Game::get_State() {
	return state;
}

Board* Game::get_Board() {
	return this->board;
}

void Game::set_Turn(COLOR turn) {
	this->turn = turn;
}

void Game::set_State(CONDITIONS state) {
	this->state = state;
}

void Game::Run_Game() {
	for (int i = 1; state == RUN; ++i) {
		cout << " Round: " << i << endl;
		board->drawBoard();
		get_Player(turn)->make_Move(board);
		if (state == RUN) turn = COLOR(1 - int(turn));
	}

	cout << " Game over " << endl;
	board->drawBoard();
	string Winner = turn == BLUE ? "BLUE" : "RED";
	cout << " The winner is: " << Winner << " Congratulations! " << endl;
}
