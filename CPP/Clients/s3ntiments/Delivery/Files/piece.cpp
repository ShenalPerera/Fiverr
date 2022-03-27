#include <iostream>
#include "game.h"
#include "piece.h"
#include "board.h"
using namespace std;

Piece::Piece(Color color, int y, int x) : 
    color(color), y(y), x(x), trapped(false) {
}

void Piece::setName(string name) {
    this->name = name;
}

string Piece::getName() const {
    return name;
}

char Piece::getLabel() const {
    char c = getName().at(0);
    if (getName() == PIECE_NAME[LEOPARD-1]){
        return color == BLUE ? 'p' : 'P';
    }
    return color == BLUE ? tolower(c) : c;
}

Color Piece::getColor() const {
    return color;
}

void Piece::setRank(int rank){
    this->rank = rank;
}

int Piece::getRank() const {
    return rank;
}

int Piece::getY() const {
    return y;
}

int Piece::getX() const {
    return x;
}

void Piece::setY(int y) {
    this->y = y;
}

void Piece::setX(int x) {
    this->x = x;
}

bool Piece::isTrapped() {
    return trapped;
}

void Piece::setTrapped(bool trapped) {
    this->trapped = trapped;
}

// Return true if p is an opponent piece of this piece, and false otherwise
bool Piece::isOpponent(Piece* p) {
    if (p != EMPTY && p->getColor() != getColor())
        return true;
    return false;
}

// Return true if this piece can capture piece p (assumed p is an opponent),
// and false otherwise
bool Piece::canCapture(Piece* p) {
    // TODO:
    // Check if this piece's rank is >= p's rank
    // Hint: remember to handle trapped situations
    // ...
    if(this->isTrapped()){
        return false;
    }
    if (p == EMPTY) return false;
    if(this->rank >= p->getRank()){
        return true;
    }
    return false;
}

// Carry out the capture of piece p
void Piece::capture(Board* board, Piece* p) {
    // TODO:
    // Remove the piece from board and opponent player's list of pieces
    // ...
    if (canCapture(p)){
        int x1 = this->getX();
        int y1 =this->getY();

        Player * player = board->getGame()->getPlayer(Color(1-int(board->getGame()->getTurn())));

        board->put(p->getY(),p->getX(), this);
        board->put(y1,x1,EMPTY);
        cout << p->getName() << " of " << player->getName() << " captured!" << endl;
        player->delPiece(p);
    }


}

// Carry out the move of this piece to (y, x)
void Piece::move(Board* board, int y, int x) {
    // TODO:
    // Hint: by calling suitable existing methods
    // capture opponent piece
    // ...
    int x1 = this->getX();
    int y1 =this->getY();
    Piece * q =  board->get(y,x);

    if(isMoveValid(board,y,x)){
        if(canCapture(q)){
            capture(board,q);
        }
        else if(isMoveValid(board,y,x)){
            board->put(y,x, this);
            board->put(y1,x1,EMPTY);

        }

        // handle rank changes when entering and leaving traps
        // ...
        if(board->isTrap(y,x, Color(1-(int)this->getColor()))){

            this->setRank(0);
            this->setTrapped(true);
        }
        else{
            int rank;
            for (int i = 0; i < PIECE_NAME->size(); ++i) {
                switch (tolower(getLabel())) {
                    case 'r':
                        rank = 1;
                        break;
                    case 'c':
                        rank = 2;
                        break;
                    case 'd':
                        rank = 3;
                        break;
                    case 'w':
                        rank = 4;
                        break;
                    case 'p':
                        rank = 5;
                        break;
                    case 't':
                        rank = 6;
                        break;
                    case 'l':
                        rank = 7;
                        break;
                    case 'e':
                        rank = 8;
                        break;
                }
            }
            this->setRank(rank);
            this->setTrapped(false);
        }
        // check winning conditions
        // (moved into opponent's den or captured all opponent pieces)
        // ...
        if(board->isDen(y,x, Color(1-(int)this->getColor())) || board->getGame()->getPlayer(Color(1-(int)this->getColor()))->getPieceCount() == 0){
            board->getGame()->setState(GAME_OVER);
        }

    }


    // carry out the move
    // ...
}

// Check if moving this piece to (y, x) is valid
// (Subclasses of Piece may override this method for defining special rules)
// [Note: you can modify this function if it doesn't fit your design]
bool Piece::isMoveValid(Board* board, int y, int x) {
    Piece* q = board->get(y, x);  // target cell
    if (isOpponent(q) && !canCapture(q))  // cell occupied by higher-rank opponent
        return false;
    if (board->isRiver(y, x))  // target is a river cell
        return false;
    if (board->isDen(y,x, this->getColor()))
        return false;
    return true;
}