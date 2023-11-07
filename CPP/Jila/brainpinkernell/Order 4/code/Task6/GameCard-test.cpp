#include <iostream>
#include <string>

#include "GameCard.h"

int main(){


    GameCard card1;
    card1.displayCard();

    GameCard card2('C',12,5);
    card2.displayCard();

    card1.setValue(11);
    card1.displayCard();

    card2.setSuit('H');
    card2.displayCard();

    cout << card2.to_string();

    return EXIT_SUCCESS;
}