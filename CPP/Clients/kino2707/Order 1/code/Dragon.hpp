#ifndef CODE_DRAGON_HPP
#define CODE_DRAGON_HPP

#include "Monster.hpp"

class Dragon : public Monster{
public:
    Dragon();
    Dragon(string,int,int, Location, Item);
    void displayDragon();
    int performFire();
};


#endif //CODE_DRAGON_HPP
