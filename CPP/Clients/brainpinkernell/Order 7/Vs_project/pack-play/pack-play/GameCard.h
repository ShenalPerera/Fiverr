#pragma once
#include <string>

using namespace std;
class GameCard {
private:
    char suit;
    int value;
    int toughness;
    int power;
    string name;

    void setName(); // This cannot be done by external user

public:
    GameCard();
    GameCard(char _suit, int _value, int _toughness, int _power);

    char getSuit() const;
    int getValue() const;
    string getName();
    int getPower() const;
    /* Toughness is an implicit value. User should know the value of the toughness by looking at the value and the suit of the card
     * /
     */
     // Mutators
    void setSuit(char _suit);
    void setValue(int _value);
    void setToughness(int _toughness);
    void setPower(int _power);
    // Cannot set the name directly. It will automatically check inside and set

    void displayCard();
    string to_string();
};

