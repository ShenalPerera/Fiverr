#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "piece.h"
#include "location.h"

using namespace std;

class Bishop : public Piece
{
 public:
    

    Bishop(bool isWhite);
    ~Bishop();



    bool canMovePiece(Location& location) const override;

    void print() const override;

};

#endif
