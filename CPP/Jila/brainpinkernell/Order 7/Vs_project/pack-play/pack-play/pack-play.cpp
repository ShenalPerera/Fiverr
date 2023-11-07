#include <iostream>

#include "CardPack.h"

using namespace std;

int main() {
    // Default constructor;
    CardPack default_card_pack;

    // Overloaded constructor
    CardPack card_pack("My card pack 1", 4);

    // Add default card to both of the pack
    GameCard default_card;
    default_card_pack.add_card(default_card);
    card_pack.add_card(default_card);

    // Check the accessors
    cout << default_card_pack.get_name() << " has " << default_card_pack.get_size() << " cards" << endl;
    cout << card_pack.get_name() << " has " << card_pack.get_size() << " cards" << endl;

    return 0;
}
