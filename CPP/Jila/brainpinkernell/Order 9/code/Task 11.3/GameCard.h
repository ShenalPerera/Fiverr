#ifndef CODE_GAMECARD_H
#define CODE_GAMECARD_H

#include <string>

#include "Rankable.h"

using namespace std;
class GameCard : public Rankable{
private:
    char suit;
    int value;
    int toughness;
    string name;

    void setName(); // This cannot be done by external user

public:
    GameCard();
    GameCard(char _suit,int _value,int _toughness);

    char getSuit();
    int getValue();
    string getName();
    /* Toughness is an implicit value. User should know the value of the toughness by lokking at the value and the suit of the card
     * /
     */
    // Mutators
    void setSuit(char _suit);
    void setValue(int _value);
    void setToughness(int _toughness);
    // Cannot set the name directly. It will automatically check inside and set

    virtual void display() ;
    virtual string to_string();
    double  compute_rank();
    bool operator==(const GameCard &rhs) const;


};


#endif //CODE_GAMECARD_H
