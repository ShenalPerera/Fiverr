#include "Item.h"
#include <vector>
#include <string>
// #pragma once

class Player
{
private:
    std::string name;
    int health;
    int attack;
    int defence;
    int damage;
    int luck;
    std::vector<Item> inventory;

public:
    Player(std::string);
    void updateStats(Item item);
    void displayStats();
    void updateAtribute(int, int, int);
    void displayAttribute();
};