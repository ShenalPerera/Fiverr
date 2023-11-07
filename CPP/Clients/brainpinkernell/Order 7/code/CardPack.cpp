#include <iostream>

#include "CardPack.h"

using namespace std;

CardPack::CardPack() {
    this->name = "Normal card pack";
    this->size = 52;
    this->cards = new GameCard[52];

}

CardPack::CardPack(string _name, int _size)  {
    this->name = _name;
    this->size = _size;
    this->cards = new GameCard[_size];

}

CardPack::~CardPack() {
    delete [] this->cards;
    this->cards = nullptr;
}

CardPack::CardPack(const CardPack &old_card_pack) {
    this->name = old_card_pack.name;
    this->size = old_card_pack.size;

    // Free if previously allocated
    this->cards = new GameCard[size];

    // Set the fields and copying
    for (int i = 0; i < size; ++i) {
        cards[i] = old_card_pack.cards[i];
    }

}

CardPack &CardPack::operator=(const CardPack &source_pack) {
    // Handle slf assignment
    if (this != &source_pack){
        this->name = source_pack.name;
        this->size = source_pack.size;


        // Free if previously allocated
        delete [] this->cards;
        this->cards = new GameCard[size];

        // Set the fields and copying
        for (int i = 0; i < size; ++i) {
            cards[i] = source_pack.cards[i];
        }
    }
    return *this;
}

string CardPack::get_name() const {
    return name;
}

int CardPack::get_size() const {
    return size;
}

GameCard CardPack::get_card_by_index(int index) {
    if (index >=0 && index < size){
        return cards[index];
    }
    cerr << "Invalid index" << endl;
    exit(0);
}



GameCard CardPack::get_first_card() {
    if (size > 0){
        return cards[0];
    }

    cerr << "Cannot perform action. deck is empty" << endl;
    exit(0);
}

void CardPack::set_name(string new_name) {
    this->name = new_name;
}

void CardPack::set_card(GameCard gameCard, int index) {
    if (index >= 0  && index < size){
        cards[index] = gameCard;
    }
}

void CardPack::add_card(GameCard gameCard) {
    GameCard * new_pointer = new GameCard[++size];
    for (int i = 0; i < size-1; ++i) {
        new_pointer[i] = cards[i];
    }
    new_pointer[size-1] = gameCard;
    delete [] cards;
    cards = new_pointer;
}

void CardPack::display() {
    cout << "Card Pack Name   : " << name << endl;
    cout << "Size of the Pack : " << size << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "card "<< i << " - " << cards[i].getName() << endl;
    }
}