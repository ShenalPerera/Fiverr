#ifndef CODE_MONSTER_HPP
#define CODE_MONSTER_HPP
#include <string>
#include "Item.hpp"

using namespace std;

class Monster {
private:
    string name;
    int level;
    int health;
    int attack;
    int defence;
    int damage;
    Location location;
    Item item;

public:
    Monster();
    Monster(std::string, int,int, Location, Item);
    int getAttack();

    void placeLocation(Location);
    void assignItem(Item);
    void getDetails() const;
};


#endif //CODE_MONSTER_HPP
