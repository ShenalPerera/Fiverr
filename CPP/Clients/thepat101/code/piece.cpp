#include <string>
#include "piece.h"
#include "player.h"

Piece::Piece(bool isWhite) : _isWhite(isWhite), _location(nullptr){
    _color = isWhite ? "W" : "B";
}

Piece::~Piece()
= default;

bool Piece::move(Player& player, Location& destLocation)
{
    bool isMoveValid = false;
    Piece* capture   = nullptr;
    Location* currentPosition = _location;

    if(_isWhite == player.isWhite() && canMovePiece(destLocation)){
        if(destLocation.occupied()){
            capture = destLocation.getPiece();

            if(capture->isWhite() != player.isWhite()) isMoveValid = true;
        }
        else isMoveValid = true;


        if(isMoveValid)
        {

            if(capture)
            {
                capture->setLocation(nullptr);
            }

            _location->setOccupier(nullptr);

            _location = &destLocation;

            _location->setOccupier(this);

            if(player.inCheck())
            {

                isMoveValid = false;
                _location = currentPosition;

                _location->setOccupier(this);

                destLocation.setOccupier(capture);


                if(capture)
                {
                    capture->setLocation(&destLocation);
                }
            }
            else
            {
                if(capture)
                {
                    player.capture(capture);
                }
            }
        }

    }
    
    return isMoveValid;
}

void Piece::setLocation(Location* location)
{
    _location = location;
}

bool Piece::isWhite() const
{
    return _isWhite;
}

string Piece::color() const
{
    return _color;
}


Location* Piece::location() const
{
    return _location;
}

