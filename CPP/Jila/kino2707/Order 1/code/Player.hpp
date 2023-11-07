#ifndef CODE_PLAYER_HPP
#define CODE_PLAYER_HPP
#include <string>
#include <vector>

#include "Item.hpp"

using namespace std;

class Player {
private:
    string name;
    int health;
    int damage;
    int attack;
    int defence;
    vector<Item> inventory;

public:
    Player();
    Player(string,int,int,int,int);

    // Actuators
    string getName() const;
    int getHealth() const;
    int getDamage() const;
    int getAttack()const;
    int getDefence() const;

    // mutators
    void setName(string);
    void setHealth(int);
    void setDamage(int );
    void setAttack(int);
    void setDefence(int );
    void addItem(Item item1);
    // Player behaviour
    void updateStat(Item);
    void updateAttribute(int ,int );

    // display
    void displayStats() const;
    void displayAttributes() const;
};


#endif //CODE_PLAYER_HPP
