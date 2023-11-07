/*
 *  square.cpp
 *  ChessProject
 */
#include "piece.h"
#include "location.h"

Location::Location(int x, int y) : _x(x), _y(y), _piece(NULL)
{
}

Location::~Location()
{
}

void Location::setOccupier(Piece* piece)
{
    _piece = piece;
}

int Location::getX() const
{
    return _x;
}

int Location::getY() const
{
    return _y;
}

bool Location::occupied() const
{
    return _piece;
}

Piece* Location::getPiece() const
{
    return _piece;
}