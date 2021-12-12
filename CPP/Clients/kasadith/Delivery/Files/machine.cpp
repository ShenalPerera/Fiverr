#include <iostream>
#include "machine.h"
#include "game.h"
#include "board.h"
#include "time.h"
#include "math.h"
using namespace std;

Machine::Machine(string name, Color color) : Player(name, color) {
    // TODO: randomize the seed of random number generator 
    //       using the current time
    srand(time(0));
}

// a sample machine that makes random valid moves
void Machine::makeMove(Board* board) {
    // TODO: make a random but valid move of a randomly picked piece on a board
    // Hint: there exist many ways to do so, one way is as follows:
    // - generate a random integer for picking a piece r from the player's pieces vector
    // - set y1, x1 to r->getY(), r->getX()
    // - generate random integers y2 and x2 in range of [0, H) and [0, W) respectively
    //   [or better in the y, x range of the 4 neighboring cells around (y1, x1), note to
    //    handle jumpable cells, 2 or 3 cells away, as well for Tiger and Lion]
    // - call board's move(y1, x1, y2, x2)
    // - once a valid move is returned, print the from and to cell addresses 
    //   and exit this function
    // Note: it can happen that no valid move can be found despite repeated picks.
    //       For example, only a Rat remains alive at a corner of the board while 
    //       the two cells it may go have been occupied by a Cat and a Dog.
    //       In this case, the player must surrender (set the opponent as winner).
    int indexOfPiece = rand() % this->getPieceCount();
    Piece * r = this->getPiece(indexOfPiece);
    int y1 = r->getY();
    int x1 = r->getX();
    int y2,x2;
    int iteration = 0;
    while(true){
        if (board->getGame()->getPlayer(Color(board->getGame()->getTurn()))->getPieceCount() == 1){
            Piece* p = board->getGame()->getPlayer(Color(board->getGame()->getTurn()))->getPiece(0);

            if (tolower(p->getLabel()) == 'r'){

                board->getGame()->setState(GAME_OVER);
                board->getGame()->setTurn(Color(1-(int)(p->getColor())));

                break;
            }
        }
        x2 =x1 + (pow(-1,rand()))* ( rand() % 2);
        y2 =y1 + (pow(-1,rand()))* ( rand() % 2);
        if (board->isMoveValid(y1,x1,y2,x2)){
            break;
        }
        if (tolower(r->getLabel()) == 't' || tolower(r->getLabel()) == 'l'){
            x2 =x1 + (pow(-1,rand()))* ( rand() % 3);
            y2 =y2 + (pow(-1,rand()))* ( rand() % 3);
            if (board->isMoveValid(y1,x1,y2,x2)){
                break;
            }
            x2 =x1 + (pow(-1,rand()))* ( rand() % 2);
            y2 =y2 + (pow(-1,rand()))* ( rand() % 2);
            if (board->isMoveValid(y1,x1,y2,x2)){
                break;
            }
        }
        iteration++;
        if (iteration > 1000 ){
            board->getGame()->setState(GAME_OVER);
            board->getGame()->setTurn(Color(1-(int)(board->getGame()->getTurn())));
            break;
        }

    }
    board->move(y1,x1,y2,x2);

}
