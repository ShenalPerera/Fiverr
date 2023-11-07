/*
 *  restrictedPiece.cpp
 *  ChessProject
 */
#include "player.h"
#include "blockedKing.h"

RestrictedPiece::RestrictedPiece(bool isWhite) : Piece(isWhite)
{
    _moved = false;
}
    
RestrictedPiece::~RestrictedPiece()
{
}

bool RestrictedPiece::move(Player& byPlayer, Location& to)
{
    bool validMove = Piece::move(byPlayer, to);

    if(validMove && !_moved)
    {
        _moved = true;
    }
    
    return validMove;
}

bool RestrictedPiece::hasMoved() const
{
    return _moved;
}

