#include <iostream>

#include "GameCard.h"

int main(){

    GameCard gameCardsArray[4] ;

    gameCardsArray[0].setValue(10);
    gameCardsArray[0].setSuit('H');
    gameCardsArray[0].setToughness(10);

    gameCardsArray[1].setValue(8);
    gameCardsArray[1].setSuit('D');
    gameCardsArray[1].setToughness(3);

    gameCardsArray[2].setValue(13);
    gameCardsArray[2].setSuit('S');
    gameCardsArray[2].setToughness(1);

    gameCardsArray[3].setValue(1);
    gameCardsArray[3].setSuit('D');
    gameCardsArray[3].setToughness(4);

    for (auto & i : gameCardsArray) {
        cout << i.to_string() << "\n-----------------------------\n" << endl;
    }

    return EXIT_SUCCESS;
}