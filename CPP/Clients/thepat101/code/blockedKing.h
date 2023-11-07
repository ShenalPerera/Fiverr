#ifndef RESTRICTED_H
#define RESTRICTED_H

#include "piece.h"

class Player;

using namespace std;

class RestrictedPiece : public Piece
{
private:
    bool _moved;

public:

    RestrictedPiece(bool isWhite);

    virtual ~RestrictedPiece();

    bool move(Player& byPlayer, Location& to) override;

    bool hasMoved() const;



};

#endif