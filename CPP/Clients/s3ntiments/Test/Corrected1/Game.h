#ifndef Game_h
#define Game_h
#include "Board.h"
#include "Player.h"

enum MODES { HVH = 1, HVM, MVM };
enum CONDITIONS { RUN, GAME_OVER };

class Game {
	private:
		Board* board;
		Player* player[2];
		COLOR turn; 
		CONDITIONS state;
	public:
		Game(MODES mode, char* gamelog);

		void set_Turn(COLOR turn);
		void set_State(CONDITIONS state);
		
		Player* get_Player(COLOR color);
		Board* get_Board();
		COLOR get_Turn();
		CONDITIONS get_State();

		void Run_Game();
};



#endif
