#ifndef PLAYER_H
#define PLAYER_H

#include <set>
#include "piece.h"
#include "king.h"

using namespace std;

class Player 
{

private:

    string _name;
    bool _isWhite;
    set<Piece*>& _myPieces;
    set<Piece*> _capturedPieces;
    King& _myKing;

public:

    Player(string name, bool isWhite, King& myKing, set<Piece*>& myPieces);

    ~Player();

    bool makeMove();

    bool inCheck();

    void capture(Piece* aPiece);

    string getName() const;

    bool isWhite() const;

    set<Piece*>* getPieces() const;

    King* myKing() const;
    
    

    
};

#endif
