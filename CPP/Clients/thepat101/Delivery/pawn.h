#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "location.h"
#include "blockedKing.h"

using namespace std;

class Pawn : public RestrictedPiece
{
 public:
    

    Pawn(bool isWhite);

    ~Pawn();

    void setLocation(Location* location) override;


    bool move(Player& byPlayer, Location& to) override;


    bool canMovePiece(Location& location) const override;


    void print() const override;
   
   
 private:

    // Private attributes
    Piece* _delegate;

}; // Pawn

#endif
