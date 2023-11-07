#ifndef CODES_NEWGAMECARD_H
#define CODES_NEWGAMECARD_H

#include <string>
#include "GameCard.h"
using namespace std;

class NewGameCard : public GameCard {
private:
    string image_URL;

public:
    NewGameCard();
    NewGameCard(char,int,int,string);

    void setImageUrl(string url);
    string getImageUrl() const;

    void display();
    string to_string();

    bool operator==(const NewGameCard &rhs) const;


};


#endif //CODES_NEWGAMECARD_H
