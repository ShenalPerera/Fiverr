#pragma once
#include <string>
#include "Item.h"
#include "Location.h"

class Monster
{
private:
    std::string name;
    int level;
    int health;
    int attack;
    int defence;
    int damage;
    Location location;
    Item item;

public:
    Monster(std::string, int, Location, Item);
    void placeLocation(Location);
    void assignItem(Item);
};