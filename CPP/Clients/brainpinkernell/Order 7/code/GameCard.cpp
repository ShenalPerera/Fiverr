#include <iostream>
#include <string>

#include "GameCard.h"

GameCard::GameCard() {
    this->name = "Ace of clubs";
    this->value = 1;
    this->suit = 'C';
    this->toughness = 13;
    this->power = 100;
    setName();
}

GameCard::GameCard(char _suit, int _value, int _toughness,int _power) {
    this->suit = _suit;
    this->value = _value;
    this->toughness = _toughness;
    this->power = _power;
    this->setName();
}

void GameCard::setName() {
    string suit_name;
    string value_name;

    switch (suit) {
        case 'H':
            suit_name = "Hearts";
            break;
        case 'C':
            suit_name = "Clubs";
            break;
        case 'D':
            suit_name = "Diamonds";
            break;
        case 'S':
            suit_name = "Spades";
            break;

    }

    switch (value) {
        case 1:
            value_name = "Ace";
            break;
        case 11:
            value_name = "Jack";
            break;

        case 12:
            value_name = "Queen";
            break;

        case 13:
            value_name = "King";
            break;

        default:
            value_name = std::to_string(value);
            break;


    }

    name = value_name + " of " + suit_name;
}

char GameCard::getSuit() const {
    return suit;
}

int GameCard::getValue() const {
    return value;
}

string GameCard::getName() {
    return name;
}

int GameCard::getPower() const {
    return this->power;
}


void GameCard::setSuit(char _suit) {
    this->suit = _suit;
    setName();
}

void GameCard::setToughness(int _toughness) {
    this->toughness = _toughness;
}

void GameCard::setValue(int _value) {
    if (_value >= 1 && _value <= 13){
        this->value = _value;
    }
    else{
        this->value = 1;
    }
    setName();

}

void GameCard::setPower(int _power) {
    this->power = _power;
}

void GameCard::displayCard() {
    cout << "This is " << name << endl;
    cout << "Value     : " << value << endl;
    cout << "Suit      : " << suit << endl;
    cout << "Power     : " << power << endl << endl;
}

string GameCard::to_string() {
    return "Name : " + name + "\nValue : " + std::to_string(value) + "\nSuit : " + suit;
}