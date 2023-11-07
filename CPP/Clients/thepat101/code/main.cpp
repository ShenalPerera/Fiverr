#include <iostream>
#include "game.h"
#include "chessBoard.h"

int main ()
{
    Player* currentPlayer = NULL;
    

    Game::initialize();
    ChessBoard::getBoard()->print(cout);
    

    while(true)
    {
        currentPlayer = Game::getNextPlayer();
        while(!currentPlayer->makeMove())
        {
            cout << "Invalid move... Try again." << endl;
        }
        ChessBoard::getBoard()->print(cout);
        char q;
        cout << "Press q to exit or any other to continue: ";
        cin >> q;

        if (tolower(q) =='q') break;
    }
    cout << "Good Bye!" << endl;
    return 0;
}
