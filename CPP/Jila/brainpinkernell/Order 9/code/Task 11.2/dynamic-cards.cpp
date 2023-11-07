#include <iostream>
#include "GameCard.h"
#include "NewGameCard.h"

#include <vector>
using namespace std;

int main(){

    vector<GameCard*> cards;

    GameCard * base_card1 = new GameCard('S',1,20);
    GameCard * base_card2 = new GameCard('H',10,2);
    GameCard * base_card3 = new GameCard('C',13,22);
    GameCard * base_card4 = new GameCard('D',1,10);

    NewGameCard * card1 = new NewGameCard('C',11,20,"www.image1.com");
    NewGameCard * card2 = new NewGameCard('D',1,12,"www.image2.com");
    NewGameCard * card3 = new NewGameCard('D',13,23,"www.image3.com");
    NewGameCard * card4 = new NewGameCard('S',3,3,"www.image5.com");

    cards.push_back(base_card1);
    cards.push_back(base_card2);
    cards.push_back(base_card3);
    cards.push_back(base_card4);

    cards.push_back(card1);
    cards.push_back(card2);
    cards.push_back(card3);
    cards.push_back(card4);

    for (int i = 0; i < cards.size(); ++i) {
        cards.at(i)->display();

    }

    for (auto & card : cards) {

        delete card;
    }

    return 0;
}