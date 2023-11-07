#include "Location.h"
#include <iostream>
#include <string>

using namespace std;

Location::Location() {}
Location::Location(string name, string description, bool hasPlayer, bool hasItem, bool hasMonster)
{
    name = name;
    description = description;
    hasPlayer = hasPlayer;
    hasMonster = hasMonster;
    hasItem = hasItem;
}

void Location::displayData()
{
    cout << name << endl
         << description << endl;
}

void Location::updateData(string name, string descrip, bool player, bool item, bool monster)
{
    name = name;
    description = descrip;
    hasPlayer = player;
    hasItem = item;
    hasMonster = monster;
}

void Location::displayHasPlayer()
{
    if (hasPlayer)
    {
        cout << "Location has a player in it";
    }
    else
    {
        cout << "Location does not have a player in it";
    }
}

void Location::displayHasMonster()
{
    if (hasMonster)
    {
        cout << "Location has a monster in it";
    }
    else
    {
        cout << "Location does not have a monster in it";
    }
}

void Location::displayHasItem()
{
    if (hasItem)
    {
        cout << "Location has an item in it";
    }
    else
    {
        cout << "Location does not have an item in it";
    }
}
