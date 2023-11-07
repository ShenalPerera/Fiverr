/*
 *  pawn.cpp
 *  ChessProject
 *
 */
#include "pawn.h"
#include "queen.h"
#include "chessBoard.h"

Pawn::Pawn(bool isWhite) : RestrictedPiece(isWhite), _delegate(NULL)
{
}

Pawn::~Pawn()
{
    if(_delegate)
        delete _delegate;
}

void Pawn::setLocation(Location* location)
{
    Piece::setLocation(location);
}


bool Pawn::move(Player& byPlayer, Location& to)
{
    bool valid = false;
    
    // if the pawn has been promoted
    if(_delegate)
    {
        // use delegate piece's movement rules to determine validity
        valid = _delegate->move(byPlayer, to);
        
        // if the move is valid, move the pawn:
        if(valid)
        {
            // unset the pawn's current square's occupant
            location()->setOccupier(NULL);
            
            // set this pawn's new location
            setLocation(&to);
            
            // set new square's occupant
            location()->setOccupier(this);
        }
    }
    else 
    {
        // otherwise, attempt to move normally as a pawn
        valid = RestrictedPiece::move(byPlayer, to);
        
        // if the move is valid and the pawn has reached the 
        // opponent's edge of the board, promote the pawn to
        // a queen
        if(valid)
        {
            if(ChessBoard::getBoard()->isEndRow(*location()))
            {
                _delegate = new Queen(isWhite());
                _delegate->setLocation(location());
            }
        }
    }
    
    return valid;
}

bool Pawn::canMovePiece(Location& location) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();
    
    // if pawn has been promoted, use it's delegate's movement rules:
    if(_delegate)
    {
        validMove = _delegate->canMovePiece(location);
    }
    // otherwise, use normal pawn movement rules:
    else 
    {
        // ("forward" is "backwards" relative to the board for black pieces)
        if(!isWhite())
        {
            translationX *= -1;
            translationY *= -1;
        }
        
        // valid move if moving 1 square forward to unoccupied square
        if(!location.occupied() && translationY == 1 && translationX == 0)
        {
            validMove = true;
        }
        
        // valid move if !moved and moving 2 squares forward
        // to unoccupied square along a clear vertical
        else if(!hasMoved() && translationY == 2 && translationX == 0 &&
                ChessBoard::getBoard()->isVertical(*(this->location()), location))
        {
            validMove = true;
        }
        
        // valid move if capturing a piece on adjacent diagonal
        else if(location.occupied() && translationY == 1 && 
                (translationX == 1 || translationX == -1))
        {
            validMove = true;
        }        
    }

    return validMove;
}

void Pawn::print() const
{
    if(_delegate)
    {
        _delegate->print();
    }
    else
    {
        cout << _color + "P";
    }
}

