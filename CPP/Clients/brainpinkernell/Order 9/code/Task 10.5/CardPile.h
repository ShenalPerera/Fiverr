#ifndef CODE_CARDPILE_H
#define CODE_CARDPILE_H

#include <string>
#include "linked-list-functs.h"
#include "GameCard.h"
#include "Node.h"

using namespace std;

class CardPile {
private:
    string name;
    int size;
    Node * cards;

public:
    // constructors
    CardPile();
    CardPile(string _name);

    string get_name() const;
    int get_size() const;
    GameCard get_top_card() const;


    // Mutators
    void set_name(string _name);

    void display() const;
    void add_card(GameCard gameCard);
    NodeDataType remove_card();

    ~CardPile();
   // CardPile(const CardPile& old);
    CardPile& operator=(const CardPile & old);
};


#endif //CODE_CARDPILE_H
