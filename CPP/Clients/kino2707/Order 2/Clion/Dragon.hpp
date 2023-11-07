#ifndef CODE_DRAGON_HPP
#define CODE_DRAGON_HPP

#include "Monster.hpp"

class Dragon : public Monster{
private:
    const int claw_level = 2;
    const int fire_level = 3;

public:
    Dragon();
    Dragon(std::string _name, int _level,int _health,int _attack,int _defence,int _damage,Location location1, Item item1);
    void displayDragon();
    int performFire();
};


#endif //CODE_DRAGON_HPP
