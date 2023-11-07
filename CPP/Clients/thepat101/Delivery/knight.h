
#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include "location.h"
#include "piece.h"

using namespace std;

class Knight : public Piece
{
 public:

    Knight(bool isWhite);

    ~Knight();

    bool canMovePiece(Location& location) const override;

    void print() const override;

}; // Knight

#endif
