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
    Monster(std::string, int,int,int,int,int, Location, Item);

    void setName(string _name);
    void setLevel(int level_);
    void setHealth(int health_);
    void setAttack(int attack_);
    void setDefence(int defence_);
    void setDamage(int damage_);

    string getName() const;
    int getLevel() const;
    int getHealth() const;
    int getAttack() const;
    int getDefence() const;
    int getDamage() const;





    void placeLocation(Location&);
    void assignItem(Item&);
    void getDetails() const;
    // copy constructor
    Monster(const Monster & monster);

};


#endif //CODE_MONSTER_HPP
