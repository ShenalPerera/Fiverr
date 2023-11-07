#include <iostream>
#include "GameCard.h"
#include "Node.h"
using namespace std;

int main(){
    cout << "Test default constructor \n";
    // check the default constructor
    Node default_node;
    default_node.display();

    cout << "\n\nTest multi-argument constructor \n";
    // Create card class
    GameCard gameCard('H',10,12);
    Node node(gameCard, nullptr);
    node.display();

    cout << "\n\nTest get_data method \n";
    node.get_data().display();

    cout << "\n\nTest set_data method \n";
    GameCard new_card('H',1,13);
    node.set_data(new_card);
    node.display();

    return 0;
}