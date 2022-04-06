#ifndef Player
#include <vector>
#include "Board.h"
#include "Animal.h"

using namespace std;

class Player {
	private:
		char* name;
		COLOR color;
		vector<Animal*> pieces;
	public:
		void set_Name(char* name);
		void set_Color(COLOR color);
		void add_Pieces(Animal* piece);

		char* get_Name();
		COLOR get_Color();
		void  remove_Pieces(Animal* piece);
		Animal* get_Piece(int position);
		int count_Pieces();
		
		virtual void make_Move(Board* board);

		Player(char* name, COLOR color);
};












#endif
