#include "queen.h"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
}

Queen::~Queen()
= default;


bool Queen::canMovePiece(Location& location) const
{
    bool isMoveValid = false;

    if(ChessBoard::getBoard()->isVertical(*(this->location()), location))
    {
        isMoveValid = true;
    }

    else if(ChessBoard::getBoard()->isHorizontal(*(this->location()), location))
    {
        isMoveValid = true;
    }

    else if(ChessBoard::getBoard()->isDiagonal(*(this->location()), location))
    {
        isMoveValid = true;
    }
    
    
    return isMoveValid;
}

void Queen::print() const
{
    cout << _color + "Q";
}