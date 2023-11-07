#include "rook.h"

Rook::Rook(bool isWhite) : RestrictedPiece(isWhite)
{
}

Rook::~Rook()
= default;


bool Rook::canMovePiece(Location& location) const
{
    bool validMove = false;

    if(ChessBoard::getBoard()->isVertical(*(this->location()), location))
    {
        validMove = true;
    }

    else if(ChessBoard::getBoard()->isHorizontal(*(this->location()), location))
    {
        validMove = true;
    }
    
    return validMove;
}

void Rook::print() const
{
    cout << _color + "R";
}