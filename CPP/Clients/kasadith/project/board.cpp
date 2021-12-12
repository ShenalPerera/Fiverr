#include <iostream>
#include <cctype>
#include "game.h"
#include "board.h"
#include "piece.h"
#include "elephant.h"
#include "lion.h"
// TODO: include more necessary headers
#include "tiger.h"
#include "dog.h"
#include "cat.h"
#include "rat.h"
#include "leopard.h"
#include "wolf.h"
#include "fileman.h"

using namespace std;

Board::Board(Game* game, char* filename) : 
    game(game), cells() {  // initialize cells' elements to nullptr
    // Set up the initial game board
    if (filename != nullptr)
        loadFromFile(filename, this);
    else
        init();
}

// initial game board configuration
void Board::init() {
    // TODO:
    // set up the Jungle chess standard initial game board properly;
    // add Elephants, Lions, ..., Rats to the cells array at correct positions
    for(int row = 0; row<H; row++){
        for(int col =0; col<W; col++){
            this->cells[row][col] =  EMPTY;

            Color color = row < 4 ? BLUE: RED;
            if(row == 0 && col == 0 || row == H-1 && col == W -1){
                this->cells[row][col] = new Lion(color,row,col);

            }
            if(row == 0 && col == W-1 || row == H-1 && col == 0){
                this->cells[row][col] = new Tiger(color,row,col);

            }
            if(row == 1 && col == 1 || row == H-2 && col == W-2){
                this->cells[row][col] = new Dog(color,row,col);

            }
            if(row == 1 && col ==  W-2 || row == H-2 && col == 1){
                this->cells[row][col] = new Cat(color, row, col);

            }
            if(row == 2 && col == 0 || row == 6 && col == 6){
                this->cells[row][col] = new Rat(color,row,col);

            }
            if(row == 2 && col == 2 || row == 6 && col == 4){
                this->cells[row][col] = new Leopard(color,row,col);

            }
            if(row == 2 && col == 4 || row == 6 && col == 2){
                this->cells[row][col] = new Wolf(color,row,col);

            }
            if(row == 2 && col == 6 || row == 6 && col == 0){
                this->cells[row][col] = new Elephant(color,row,col);
            }
            if(row == 3 || row == 4 || row == 5){
                if(col % 3 != 0){
                    this->cells[row][col] = RIVER_CELL;
                }
            }

            if(row == 0 &&  col == 3 || row == 8 && col == 3){
                this->cells[row][col] = DEN;
            }
            if(row == 0 || row == 8){
                if (col == 2 || col == 4){
                    this->cells[row][col] =  TRAP;
                }
            }
            if(row == 1 && col == 3 || row == 7  && col == 3){
                this->cells[row][col] =  TRAP;

            }
            if(this->cells[row][col] != EMPTY){
                game->getPlayer(color)->addPiece(this->cells[row][col]);
            }

        }
    }
    // TODO: also add the created pieces to each player's vector of pieces
}

// Return true if (y, x) is an empty cell, and false otherwise
bool Board::isEmpty(int y, int x) {
    if (cells[y][x] == EMPTY)
        return true;
    return false;
}

// Return true if (y, x) is the den on the side of the specified color, 
// and false otherwise
bool Board::isDen(int y, int x, Color color) {

    // TODO: Add your code here
    if(x == 3 ){
        if (y == 0 && color == BLUE){
            return true;
        }
        if (y == 8 && color == RED){
            return true;
        }
    }
    return false;
}

// Return true if (y, x) is a trap on the side of the specified color, 
// and false otherwise
bool Board::isTrap(int y, int x, Color color) {
    // TODO: Add your code here
    if (x == 2 || x == 4){
        if(y == 0 && color == BLUE){
            return true;
        }
        if(y==8 && color == RED){
            return true;
        }
    }
    if (x == 3){
        if (y == 1 && color == BLUE) return true;
        if (y == 7 && color == RED) return true;
    }
    return false;
}

// Return true if (y, x) is a river cell, and false otherwise
bool Board::isRiver(int y, int x) {
    return y >= 3 && y <= 5 && (x >= 1 && x <= 2 || x >= 4 && x <= 5);
}

// Get a piece from the specified cell
Piece* Board::get(int y, int x){
    if (0 <= y && y < H && 0 <= x && x < W)
        return cells[y][x];
    return OUT_BOUND; // out of bound
}

// Put piece p onto the specified cell
void Board::put(int y, int x, Piece* p){
    cells[y][x] = p;
    if (p != EMPTY) {
        p->setY(y);
        p->setX(x);
    }
}

// Print the game board
void Board::print() {
    // TODO: Add code to print the HxW gameboard by looping over cells array
    // Hint: Make use of isEmpty(), isRiver(), isTrap(), isDen(), and 
    //       getLabel() of Piece to ease your work
    // Remember * for river cells, # for trap cells, X for den cells
    cout << "    A   B   C   D   E   F   G\n";
    cout <<"  +---+---+---+---+---+---+---+\n";
    for(int i =0; i<H;i++){
        cout << i+1 << " ";
        for(int j=0; j<W;j++){

            if (isDen(i,j,BLUE) || isDen(i,j,RED)){
                if (this->cells[i][j] == EMPTY || isDen(i,j,BLUE) || isDen(i,j,RED)){
                    cout << "| X ";
                }
                else{
                    cout << "| " << cells[i][j]->getLabel()  << " ";
                }
            }
            else if (isTrap(i,j,RED) || isTrap(i,j,BLUE)){
                if (this->cells[i][j] == EMPTY || isTrap(i,j,RED) || isTrap(i,j,BLUE)){
                    cout << "| # ";
                }
                else{
                    cout << "| " << cells[i][j] << " ";
                }

            }
            else if(isRiver(i,j)){
                if (this->cells[i][j] == EMPTY || this->isRiver(i,j)){
                    cout << "| X ";
                }
                else if (tolower(this->cells[i][j]->getLabel()) == 'r' ){
                    cout << "| " << cells[i][j]->getLabel()  << " ";
                }
            }
            else if(isEmpty(i,j)){
                cout << "|   ";
            }
            else{
                cout << "| " << cells[i][j]->getLabel()  << " ";
            }

        }
        cout << "|\n";
        cout <<"  +---+---+---+---+---+---+---+\n";



    }
}

// Check if the move from (y1, x1) to (y2, x2) is valid
bool Board::isMoveValid(int y1, int x1, int y2, int x2) {
    // TODO:
    // check against invalid cases, for example,
    // - the source is an empty cell
    // - the source and destination are the same position
    // - the destination is out of bound of the board (hint: use OUT_BOUND)
    // - the source piece is not of same color of current turn of the game
    // (... and anymore ?)
    // [Note: you can modify the following code if it doesn't fit your design]
    if(this->get(y1,x1) == EMPTY || y1 == y2 && x1 == x2 || this->get(y2,x2) == OUT_BOUND){
        return false;
    }
    if(!(y1 == y2 && x1 != x2 || x1 == x2 && y1 != y2)){
        return false;
    }

    if (getGame()->getTurn() != this->get(y1,x1)->getColor()) {
        return false;
    }
    // Piece-specific validation
    Piece * p = this->get(y1,x1);
    if (!p->isMoveValid(this, y2, x2)){
        return false;
    }


    return true;
}

// Carry out the move from (y1, x1) to (y2, x2)
bool Board::move(int y1, int x1, int y2, int x2) {
    if (isMoveValid(y1, x1, y2, x2)) {
        get(y1, x1)->move(this, y2, x2);
        return true;
    }
    return false;
}

// Return the pointer to the Game object
Game* Board::getGame() const {
    return game;
}
