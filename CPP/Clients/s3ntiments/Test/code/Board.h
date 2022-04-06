#ifndef Board_h
#define Board_h
#include <string>

using namespace std;

class Animal;
class Game;
Animal* const EMPTY = nullptr;
Animal* const DEN = (Animal*)'X';
Animal* const RIVER = (Animal*)'*';
Animal* const TRAP = (Animal*)'#';
Animal* const OUTBOUNDS = (Animal*)-1;
enum COLOR : int;

class Board {
	public:
		const static int width = 7;
		const static int height = 9;
		
		void initBoard();
		bool isEmpty(int x, int y);
		bool isTrap(int x, int y, COLOR color);
		bool isRiver(int x, int y);
		bool isDen(int x, int y, COLOR color);

		Animal* getPiece(int x, int y);
		void setPiece(int x, int y, Animal* piece);
		void drawBoard();
		bool isMoveValid(int x1, int y1, int x2, int y2);
		bool MovePiece(int x1, int y1, int x2, int y2); 
		Game* getGame() const;
		Board(Game* game, char* filename);
	
	protected:
		Animal* arr[height][width];
		Game* game;
};


#endif
