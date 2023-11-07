#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include "blockedKing.h"
#include "location.h"

using namespace std;

class Rook : public RestrictedPiece
{
 public:

    Rook(bool isWhite);

    ~Rook();

    bool canMovePiece(Location& location) const override;

    void print() const override;

};

#endif
