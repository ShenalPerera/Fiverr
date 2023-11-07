#include "knight.h"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
}

Knight::~Knight()
= default;

bool Knight::canMovePiece(Location& location) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();

    if(abs(translationY) == 1 && abs(translationX) == 2)
    {
        validMove = true;
    }

    else if(abs(translationX) == 1 && abs(translationY) == 2)
    {
        validMove = true;
    }
    
    return validMove;
}

void Knight::print() const
{
    cout << _color + "N";
}



