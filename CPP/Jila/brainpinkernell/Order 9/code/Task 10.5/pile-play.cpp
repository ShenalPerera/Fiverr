#include <iostream>
#include "CardPile.h"
#include "Node.h"
#include "GameCard.h"

using namespace std;

int main(){
    cout << "Testing constructors\n";
    CardPile pile1;
    CardPile pile2("This is non- default card pile");

    pile1.display();
    cout << "-----------------------------------\n";
    pile2.display();

    cout << "\n\nTesting add methods\n";
    GameCard card1('H',10,10);
    GameCard card2('C',12,20);
    GameCard card3('D',11,11);

    pile2.add_card(card1);
    pile2.add_card(card2);
    pile2.add_card(card3);

    pile2.display();

    cout << "\n\nTesting getters\n";
    if (pile2.get_size() != 3){
        cout << "get_size function have an error\n";
    }
    else{
        cout << "get_size function passed\n";
    }

    if (pile2.get_name() != "This is non- default card pile"){
        cout << "get_name function have an error\n";
    }
    else{
        cout << "get_name function passed\n";
    }

    cout << "\n\nTesting setters\n";
    pile1.set_name("This is new name");
    cout << "Expected : This is new name | Actual : " << pile1.get_name() << " | Result : Pass |\n";


    cout << "\n\nTesting remove function\n";
    GameCard game_card = pile2.remove_card();

    cout << "Expected Size : 2 | Actual size : " << pile2.get_size() << " | Pass\n";
    cout << "Expected to_string : " << card3.to_string() << "| Actual : " << game_card.to_string() << " | pass\n";

    cout << "\n\nTesting copy constructor\n";
    pile1.add_card(card1);
    CardPile pile = pile1;
    //pile3.display();
    pile.operator=(pile1);
//    pile1.display();
    return 0;
}