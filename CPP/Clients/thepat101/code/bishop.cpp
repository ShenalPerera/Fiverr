#include "bishop.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite){}

Bishop::~Bishop()
= default;

bool Bishop::canMovePiece(Location& location) const
{
    bool validMove = false;

    if(ChessBoard::getBoard()->isDiagonal(*(this->location()), location))
    {
        validMove = true;
    }
    
    return validMove;
}

void Bishop::print() const
{
    cout << _color + "B";
}