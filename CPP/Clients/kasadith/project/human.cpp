#include <iostream>
#include "human.h"
#include "game.h"
#include "board.h"
#include "limits"
using namespace std;

Human::Human(string name, Color color) : Player(name, color) { }

void Human::makeMove(Board* board) {
    while (true) {
        cout << this->getName() <<  "'s turn: ";
        char c1, c2;    // columns letters
        int r1, r2;     // row indexes (begin at 1)
        cin >> c1 >> r1 >> c2 >> r2;
        // if input fails, reset cin's state, skip the buffer and try again
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid. Try again!" << endl;
            continue;
        }
        
        // ad hoc stop condition (surrender)
        if (c1 == 'Z' && c2 == 'Z' && r1 == 0 && r2 == 0) {
            board->getGame()->setState(GAME_OVER);
            // TODO: set opponent as winner, 
            // e.g. by flipping the turn (if you assumed the player 
            // making the last turn before game over is the winner)
            board->getGame()->setTurn(Color(1 - (board->getGame()->getTurn())));
            return;
        }
        
        // TODO:
        // Convert r1, c1 and r2, c2 into integers y1, x1, y2, x2 
        int y1 = r1 -1;
        int y2 = r2 -1;

        int x1 =  c1 - 'A';
        int x2 =  c2 - 'A';



        bool valid = board->move(y1, x1, y2, x2);
        if (valid)
            break;
        cout << "Invalid. Try again!" << endl;
    }
}
