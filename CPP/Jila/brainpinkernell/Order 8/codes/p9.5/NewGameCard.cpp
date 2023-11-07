#include <iostream>
#include "NewGameCard.h"

NewGameCard::NewGameCard() : image_URL("invalid url") {}

NewGameCard::NewGameCard(char suit_, int value, int toughness_, std::string url) : GameCard(suit_,value,toughness_),image_URL(url) {}

string NewGameCard::getImageUrl() const {
    return image_URL;
}

void NewGameCard::setImageUrl(std::string url) {
    image_URL = url;
}

void NewGameCard::display()  {
    cout << "Image URL : " << image_URL << endl;
    cout << "This is " << getName() << endl;
    cout << "Value     : " << getValue() << endl;
    cout << "Suit      : " << getSuit() << endl;
}

string NewGameCard::to_string() {
    return "Image Url : " +image_URL + "\nName : " + getName() + "\nValue : " + std::to_string(getValue()) + "\nSuit : " + getSuit();
}

bool NewGameCard::operator==(const NewGameCard &rhs) const {
    return static_cast<const GameCard &>(*this) == static_cast<const GameCard &>(rhs) &&
           image_URL == rhs.image_URL;
}



