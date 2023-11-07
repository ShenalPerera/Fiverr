#ifndef PIECE_H
#define PIECE_H

#include <ostream>
#include "location.h"
#include "chessBoard.h"
class Player;

using namespace std;

class Piece{
protected:
    bool _isWhite;
    string _color;

private:
    Location* _location;
 public:

    Piece(bool isWhite);

    virtual ~Piece();

    virtual bool move(Player& player, Location& destLocation);

    virtual void setLocation(Location* location);

    bool isWhite() const;

    string color() const;

    virtual void print() const = 0;

    virtual bool canMovePiece(Location& location) const = 0;

    Location* location() const;


};

#endif
