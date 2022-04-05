#include <bits/stdc++.h>
#include "Filemanager.h"
#include <fstream>
#include "Animal.h"
#include "Lion.h"
#include "Cat.h"
#include "Dog.h"
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

	}

}