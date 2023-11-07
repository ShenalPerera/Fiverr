#pragma once
#include "Location.h"
#include <string>

using namespace std;

enum ItemType
{
    artefact,
    potion,
    weapon,
    armour,
    item
};

class Item
{
private:
    std::string name;
    ItemType type;
    int numOfUses;
    Location location;
    std::string specialEffects;
    bool usable;

public:
    Item(std::string, ItemType, Location, int, std::string);
    void placeLocation(Location);
    void makeUsable();
    void displayName();
};