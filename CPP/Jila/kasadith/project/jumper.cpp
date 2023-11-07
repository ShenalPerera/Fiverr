#include "jumper.h"
#include <algorithm>
#include "piece.h"
using namespace std;

Jumper::Jumper() {
}

/* Check if animal p can jump over a river
   The 'steps' argument is used to control how many river cells to test.
   Call isJumpable(board, p, y, x, 2) to test if p can do a horizontal river jump (2 steps)
   Call isJumpable(board, p, y, x, 3) to test if p can do a vertical river jump (3 steps)
   Return true if p can jump and false otherwise (e.g. due to blocking by a Rat in river)
 */
bool Jumper::isJumpable(Board* board, Piece* p, int y, int x, int steps) {
    /* TODO: Add code to check if p can jump over 'steps' river squares 
             to the destination(y, x) */
    Piece* q = board->get(y,x);
    int y1,y2,x1,x2;

    y1 = p->getY();
    x1 = p->getX();
    if (q == EMPTY) return true;
    y2 = q->getY();
    x2 = q->getX();

    for(int i=0; i<steps;i++){
        if(x2 - x1 == 0){
            if (board->get(i+1,x2) != EMPTY){
                if(board->get(i+1,x2)->getRank() == RAT) return false;
            }

        }
        if(y2-y1 == 0){
            if (board->get(y2,i+1) != EMPTY){
                if(board->get(y2,i+1)->getRank() == RAT) return false;
            }

        }
    }
    if((abs(y2 - y1) == steps && x1-x2 ==0) || (abs(x2-x1) == steps && y1 -y2 ==0)){
        return true;
    }
}