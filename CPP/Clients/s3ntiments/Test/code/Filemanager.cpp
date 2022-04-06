#include <bits/stdc++.h>
#include "Filemanager.h"
#include <fstream>
#include "Animal.h"
#include "Lion.h"
#include "Cat.h"
#include "Dog.h"
#include "Wolf.h"
#include "Leopard.h"
#include "Elephant.h"
#include "Rat.h"
#include "Tiger.h"
#include <cctype>

using namespace std;

void readBoard(const char* filename, Board* board) {
	ifstream fin(filename);

	if (fin.fail()) {
		cout << " Game is finished " << endl;
		exit(1);
	}

	int row, r, c;
	char col, label;
	while (!fin.eof()) {
		fin >> col >> row >> label;

		if (fin.fail() && !fin.eof()) {
			cout << " Error in reading file! " << endl;
			exit(1);
		}
		if (fin.fail()) {
			break;
		}

		c = col - 'A';
		r = row - 1;

		if (c > Board::width - 1 || r > Board::height - 1 || c < 0 || r < 0) {
			cout << " Column or Row out of bounds! " << endl;
			exit(1);
		}

		Animal* piece;
		COLOR color = isupper(label) ? RED : BLUE;
		switch (toupper(label)) {
			case 'E':
				piece = new Elephant(color, r, c);
				break;
			case 'R':
				piece = new Rat(color, r, c);
				break;
			case 'L':
				piece = new Lion(color, r, c);
				break;
			case 'T':
				piece = new Tiger(color, r, c);
				break;
			case 'P':
				piece = new Leopard(color, r, c);
				break;
			case 'W':
				piece = new Wolf(color, r, c);
				break;
			case 'D':
				piece = new Dog(color, r, c);
				break;
			case 'C':
				piece = new Cat(color, r, c);
				break;
			default:
				cout << " Please enter a valid label " << endl;
				exit(1);
		}

		board->setPiece(r, c, piece);
	}
}