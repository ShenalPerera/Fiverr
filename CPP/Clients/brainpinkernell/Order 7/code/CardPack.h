#ifndef CODE_CARDPACK_H
#define CODE_CARDPACK_H
#include "GameCard.h"
#include <string>

using namespace std;

class CardPack {
private:
    string name;
    int size;
    GameCard * cards;


public:
    // Default constructors
    CardPack();

    // Overloaded constructor
    CardPack(string _name,int _size);

    // destructor
    ~CardPack();

    // copy constructor
    CardPack(const CardPack& old_card_pack);

    // Overloaded assignment operator
    CardPack& operator =(const CardPack & source_pack);

    // Accessors
    string get_name() const;
    int get_size() const;
    GameCard get_card_by_index(int index);
    GameCard get_first_card();

    // Mutators
    void set_name(string new_name);
    void set_card(GameCard  gameCard, int index);
    void add_card(GameCard gameCard);        //This will add the card to last position

    // Display functions
    void display();


};


#endif //CODE_CARDPACK_H
