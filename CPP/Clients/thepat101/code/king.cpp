#include "king.h"

King::King(bool isWhite) : RestrictedPiece(isWhite){}

King::~King()
= default;

bool King::canMovePiece(Location& location) const
{
    bool validMove = false;
    int mapX = location.getX() - this->location()->getX();
    int mapY = location.getY() - this->location()->getY();
    

    if(abs(mapY) == 1 && mapX == 0)
    {
        validMove = true;
    }

    else if(abs(mapX) == 1 && mapY == 0)
    {
        validMove = true;
    }
    else if(abs(mapX) == 1 && abs(mapY) == 1)
    {
        validMove = true;
    }
    
    return validMove;
}

void King::print() const
{
    cout << _color + "K";
}
