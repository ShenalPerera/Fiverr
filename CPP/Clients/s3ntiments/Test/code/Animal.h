#ifndef Animal_H
#define Animal_H

#include "Board.h"
#include <string>


enum RANKS { RAT = 1, CAT, DOG, WOLF, LEOPARD, TIGER, LION, ELEPHANT };
enum COLOR : int {BLUE, RED};
string animalNames[] = { "RAT", "CAT", "DOG", "WOLF", "LEOPARD", "TIGER", "LION", "ELEPHANT" };

class Animal {
private:
	string name;
	int rank;
	int X; int Y;
	bool Trap;
	bool River;
	bool Den;
	COLOR color;
public:
	void setName(string inputname);
	void setRank(int inputrank);
	void setX(int inputX);
	void setY(int inputY);
	void setisTrap(bool istrap);
	void setisRiver(bool isriver);
	void isDen(bool den);
	void setColor(COLOR inputcolor);

	string getName();
	int getRank();
	int getX();
	int getY();
	bool getisTrap();
	bool getisRiver();
	bool getisDen();
	COLOR getColor();

	virtual bool isMoveValid(Board* board, int x, int y);
	bool isOpponent(Animal* piece);
	virtual bool canEat(Animal* rank);
	virtual void Eat(Board* board, Animal* piece);

	virtual char getLabel();
	void MovePiece(Board* board, int x, int y);
	Animal(COLOR color, int X, int Y);
};

#endif