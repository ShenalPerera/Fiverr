#include "chessBoard.h"
#include "piece.h"

ChessBoard::ChessBoard(){

    for (int i = 0; i < _LENGTH; i++){
        for (int j = 0; j < _LENGTH; j++){
            _squares[i][j] = new Location(i, j);
        }
    }
}

ChessBoard::~ChessBoard(){
    for (auto & _square : _squares){
        for (auto & j : _square){
            delete[] j;
        }
        delete * _square;
    }
    delete ** _squares;
}

ChessBoard* ChessBoard::getBoard(){
    if (!chessBoard)
        chessBoard = new ChessBoard();
    return chessBoard;
}

Location* ChessBoard::getLocationAt(int x, int y) const
{
    return _squares[x][y];
}

bool ChessBoard::isVertical(Location& from, Location& to) const
{
    Location* start = nullptr;
    Location* end = nullptr;
    bool valid = true;

    if(from.getY() <= to.getY())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }

    if(start->getX() != end->getX())
    {
        valid = false;
    }
    else 
    {

        for(int i = start->getY() + 1; i < end->getY(); i++)
        {
            if(getLocationAt(start->getX(), i)->occupied())
            {
                valid = false;
            }
        } 
    }
    
    return valid;
}

bool ChessBoard::isHorizontal(Location& from, Location& to) const
{
    Location* start = nullptr;
    Location* end = nullptr;
    bool valid = true;

    if(from.getX() <= to.getX())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }

    if(start->getY() != end->getY())
    {
        valid = false;
    }
    else 
    {
        for(int i = start->getX() + 1; i < end->getX(); i++){
            if(getLocationAt(i, start->getY())->occupied()){
                valid = false;
            }
        } 
    }
    
    return valid;
}

bool ChessBoard::isDiagonal(Location& from, Location& to) const
{
    bool valid = true;
    int translationX = to.getX() - from.getX();
    int translationY = to.getY() - from.getY();
    int xDir = 1;
    int yDir = 1;
    
    if(translationX < 0)
    {
        xDir = -1;
    }
    
    if(translationY < 0)
    {
        yDir = -1;
    }

    if(abs(translationX) != abs(translationY))
    {
        valid = false;
    }
    else 
    {
        for(int i = 1; i < abs(translationX); i++)
        {
            if(getLocationAt(from.getX() + (i * xDir), from.getY() + (i * yDir))->occupied())
            {
                valid = false;
            }
        }
    }
    
    return valid;
}

bool ChessBoard::isEndRow(Location& location) const
{
    return (location.getY() == 0 || location.getY() == (_LENGTH - 1));
}

void ChessBoard::print(ostream& outStream) const
{
    outStream << endl << "   A  B  C  D  E  F  G  H" << endl;
    outStream         << " -------------------------" << endl;
    for (int y = _LENGTH - 1; y >= 0; y--){
        outStream << y + 1;
        for (const auto & _square : _squares)
        {
            outStream << "|";
            if(_square[y]->occupied())
                _square[y]->getPiece()->print();
            else
                outStream << "  ";
        }
        outStream << "|" << y + 1 << endl << " -------------------------" << endl;
    }
    outStream << "   A  B  C  D  E  F  G  H" << endl << endl;
}

ChessBoard* ChessBoard::chessBoard = nullptr;