#include "Item.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Location.h"

using namespace std;

Item::Item(string name, ItemType type, Location locate, int use, string effects)
{
    name = name;
    type = type;
    numOfUses = use;
    specialEffects = effects;
    makeUsable();
    placeLocation(locate);
}

void Item::displayName()
{
    cout << name;
}

void Item::makeUsable()
{
    if (numOfUses <= 0)
    {
        usable = false;
    }
    else
    {
        usable = true;
    }
}

void Item::placeLocation(Location locate)
{
    location = locate;
}