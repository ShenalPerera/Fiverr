#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include "location.h"

using namespace std;

class ChessBoard
{
private:

    ChessBoard();
    static ChessBoard* chessBoard;
    static const int _LENGTH = 8;
    Location* _squares[_LENGTH][_LENGTH];

 public:

    ~ChessBoard();

    static ChessBoard* getBoard();

    Location* getLocationAt(int x, int y) const;

    bool isVertical(Location& from, Location& to) const;

    bool isHorizontal(Location& from, Location& to) const;

    bool isDiagonal(Location& from, Location& to) const;

    bool isEndRow(Location& location) const;

    void print(ostream& outStream) const;


};

#endif
