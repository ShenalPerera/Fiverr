#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "location.h"
#include "piece.h"

using namespace std;

class Queen : public Piece
{
 public:

    Queen(bool isWhite);

    ~Queen();

    bool canMovePiece(Location& location) const override;

    void print() const override;

}; // Queen

#endif