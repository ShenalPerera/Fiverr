/**
 * square.h
 *
 * This class represents a square on a game board.
 *
 */

#ifndef SQUARE_H
#define SQUARE_H

class Piece;

using namespace std;

class Location
{
private:


    int _x;
    int _y;
    Piece* _piece;
 public:
   

    Location(int x, int y);
    Location();

    ~Location();

    void setOccupier(Piece* piece);

    int getX() const;

    int getY() const;

    bool occupied() const;   

    Piece* getPiece() const;




}; // Location

#endif
