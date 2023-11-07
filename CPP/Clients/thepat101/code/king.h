#ifndef KING_H
#define KING_H

#include <iostream>
#include "blockedKing.h"

using namespace std;

class King : public RestrictedPiece
{
 public:

    King(bool isWhite);

    ~King();

    bool canMovePiece(Location& location) const override;


    void print() const override;

};

#endif
