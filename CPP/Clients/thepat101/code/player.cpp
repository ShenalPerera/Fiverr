#include <iostream>
#include "player.h"
#include "chessBoard.h"
#include "game.h"

#define X_MIN 'a'
#define X_MAX 'h'
#define Y_MIN '1'
#define Y_MAX '8'

Player::Player(string name, bool isWhite, King& myKing, set<Piece*>& myPieces) :
_name(name), _isWhite(isWhite), _myPieces(myPieces), _myKing(myKing)
{
}

Player::~Player()
= default;

bool Player::makeMove()
{
    string badInput;
    string fromSquare =  "  ";
    string toSquare = "  ";
    int fromX;
    int fromY;
    int toX;
    int toY;

    if(inCheck())
    {
        cout << _name << " is in check!" << endl;
    }

    cout << _name << " player enter move [ a1 a5 ] : ";
    cin >> fromSquare >> toSquare;

    while(fromSquare.length() != 2 ||
          toSquare.length() != 2 ||
          tolower(fromSquare.at(0)) < X_MIN ||
          tolower(fromSquare.at(0)) > X_MAX ||
          tolower(toSquare.at(0)) < X_MIN ||
          tolower(toSquare.at(0)) > X_MAX ||
          tolower(fromSquare.at(1)) < Y_MIN ||
          tolower(fromSquare.at(1)) > Y_MAX ||
          tolower(toSquare.at(1)) < Y_MIN ||
          tolower(toSquare.at(1)) > Y_MAX

          )
    {
        if ((ChessBoard::getBoard()->getLocationAt(tolower(fromSquare.at(0)) - X_MIN,
                                                    tolower(fromSquare.at(1)) - Y_MIN)->occupied())){

        }
        cerr << "Invalid move. Try again." << endl;
        cin.clear();
        getline(cin, badInput);
        cout << _name << " player enter move (e.g. a1 a5): ";
        cin >> fromSquare >> toSquare;
    }
    

    fromX = tolower(fromSquare.at(0)) - X_MIN;
    fromY = tolower(fromSquare.at(1)) - Y_MIN;
    toX = tolower(toSquare.at(0)) - X_MIN;
    toY = tolower(toSquare.at(1)) - Y_MIN;


    return ChessBoard::getBoard()->getLocationAt(fromX, fromY)->getPiece()->move(*this,
                                                                                 *(ChessBoard::getBoard()->getLocationAt(
                                                                                         toX, toY)));
}

bool Player::inCheck()
{
    bool check = false;

    for (auto itr : *Game::opponentOf(*this)->getPieces())
    {
        if (((Piece*)itr)->location() &&
                ((Piece *) itr)->canMovePiece(*(myKing()->location())))
        {

            check = true;
        }
    }
    
    return check;
}

void Player::capture(Piece* aPiece)
{
    aPiece->setLocation(nullptr);

    _capturedPieces.insert(aPiece);
}

string Player::getName() const
{
    return _name;
}

bool Player::isWhite() const
{
    return _isWhite;
}


set<Piece*>* Player::getPieces() const
{
    return &_myPieces;
}

King* Player::myKing() const
{
    return &_myKing;
}