#include <iostream>

#include "CardPack.h"

using namespace std;

int main() {
    // Default constructor;
    CardPack default_card_pack;

    // Overloaded constructor
    CardPack card_pack("My card pack 1",4);



    // Check the accessors
    cout << default_card_pack.get_name() << "  size is " <<default_card_pack.get_size() << endl;
    cout << card_pack.get_name() <<  " size is " << card_pack.get_size() << endl;

    cout << "Default card pack 0th card : ==> " << default_card_pack.get_first_card().to_string() << endl;
    cout << card_pack.get_name() << " : ==> " << card_pack.get_first_card().to_string() << endl;

    cout <<"\n\nCheck get by index \n" <<card_pack.get_card_by_index(0).to_string() << endl;


    // check the mutators
    cout << "\n\nChange the name of the card pack" << endl;
    card_pack.set_name("Navy Seals");
    cout << card_pack.get_name() << endl;

    cout << "\n\nChange the card of position 1 of the card pack" << endl;
    // Add default card to both of the pack
    GameCard default_card('H',12,11,100);

    card_pack.set_card(default_card,1);
    card_pack.display();

    cout << "\n\nAdd a new card" << endl;
    GameCard new_card('D',11,12,111);
    card_pack.add_card(new_card);
    cout << "New size is : " << card_pack.get_size() << endl;
    card_pack.display();

    cout << "\n\nCheck copy constructor" << endl;
    cout << "Create new card pack using copy constructor" << endl;
    CardPack new_card_pack(card_pack);
    card_pack.set_card(new_card,0);
    new_card_pack.display();
    cout << "\n\nChange is not affected\n" << endl;
    card_pack.display();


    cout << "\n\nCheck assignment operator" << endl;

    new_card_pack = card_pack;

    card_pack.set_card(new_card,1);
    new_card_pack.display();
    cout << "\n\nChange is not affected\n" << endl;
    card_pack.display();
    return 0;
}
