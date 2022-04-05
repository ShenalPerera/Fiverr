#include "Player.h"
#include <bits/stdc++.h>

using namespace std;

Player::Player(char* name, COLOR color) {
	this->name = name;
	this->color = color;
}

COLOR Player::get_Color() {
	return this->color;
}

char* Player::get_Name() {
	return this->name;
}

Animal* Player::get_Piece(int position) {
	return pieces.at(position);
}

void Player::add_Pieces(Animal* piece) {
	this->pieces.push_back(piece);
}


void Player::remove_Pieces(Animal* piece) {
	for (int i = 0; i < pieces.size(); ++i) {
		if (piece->getLabel() == this->pieces.at(i)->getLabel()) {
			pieces.erase(this->pieces.begin() + i);
		}
	}
}

int Player::count_Pieces() {
	return this->pieces.size();
}