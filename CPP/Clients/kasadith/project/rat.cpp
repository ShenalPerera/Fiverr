#include "rat.h"
#include <iostream>

using namespace std;

Rat::Rat(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[RAT-1]);
    setRank(RAT);
}

bool Rat::isMoveValid(Board* board, int y, int x) {
    // TODO: Override the superclass version of valid move checks
    // e.g., to allow a Rat to move into a square occupied by an Elephant
    //       to allow a Rat to enter a water square
    Piece *q = board->get(y,x);
    if(abs(getY() - y) + abs(getX() - x) != 1) return false;

    if(isOpponent(q) && canCapture(q)){
        if(board->isRiver(y,x) != board->isRiver(getY(),getX())){
            return false;
        }
        return true;
    }
    else{
        if (q == EMPTY || q == TRAP ) return true;
        return false;
    }

}

bool Rat::canCapture(Piece* p) {
    // TODO: Override the superclass version of capture checks
    // A Rat can capture an Elephant
    if(this->isTrapped()){
        return false;
    }
    if (p == EMPTY) return false;
    if(p->getRank() == ELEPHANT || p->getRank() <= this->getRank()){
        return true;
    }
    return false;
}