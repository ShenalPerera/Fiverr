#include <iostream>

#include "NewGameCard.h"

using namespace std;

int main(){

    NewGameCard newGameCard1('H',12,10,"www.image/hearts.jpg");
    NewGameCard newGameCard2;

    cout << "Card 1 suit    | Expected H | Result " << newGameCard1.getSuit() << " |\n";
    cout << "Card 2 suit    | Expected C | Result " << newGameCard2.getSuit() << " |\n";

    cout << "\nChange the value and the image url\n";

    newGameCard2.setValue(2);
    newGameCard2.setImageUrl("www.image/hearts/2/");

    cout << "Card 2 value        | Expected 2 | Result " << newGameCard1.getValue() << " |\n";
    cout << "Card 2 image Url    | Expected www.image/hearts/2/ | Result " << newGameCard2.getImageUrl() << " |\n";

    cout << "\nRedefined display method results ==> image URL additional field\n" << endl;
    newGameCard2.display();

    cout << "\nRedefined to_string method results ==> image URL additional field\n" << endl;
    cout << newGameCard2.to_string() << endl<< endl;


    NewGameCard gameCard1('H',12,10,"test1.url");
    NewGameCard gameCard2('H',12,10,"test1.url");
    NewGameCard gameCard('C',10,12,"test3");
    NewGameCard gameCard3('H',9,6,"test3");

    cout << "Check overloaded == operator\n";
    cout << "Test card to itself                |    Expected 1    |    Result " << (gameCard1 == gameCard1) << "    |\n";
    cout << "Test card to identical card        |    Expected 1    |    Result " << (gameCard1 == gameCard2) << "    |\n";
    cout << "Test two different cards           |    Expected 0    |    Result " << (gameCard1 == gameCard) << "    |\n";
    cout << "Test two different cards  ()image url same)         |    Expected 0    |    Result " << (gameCard3 == gameCard) << "    |\n";
    return EXIT_SUCCESS;
}