#include <iostream>
#include "GameCard.h"

using namespace std;

int main(){
    GameCard gameCard1('H',12,10);
    GameCard gameCard2('H',12,10);
    GameCard gameCard('C',10,12);

    cout << "Test card to itself                |    Expected 1    |    Result " << (gameCard1 == gameCard1) << "    |\n";
    cout << "Test card to identical card        |    Expected 1    |    Result " << (gameCard1 == gameCard2) << "    |\n";
    cout << "Test two different cards           |    Expected 0    |    Result " << (gameCard1 == gameCard) << "    |\n";
    return EXIT_SUCCESS;
}