#include"Monster.h"
#include"Location.h"
#include"Player.h"
#include"Item.h"
#include <string>


Monster::Monster(string name, int level, Location locate, Item item)
{
    name = name;
    level = level;
    placeLocation(locate);
    assignItem(item);
}

void Monster::placeLocation(Location locate)
{
	location = locate;
}

void Monster::assignItem(Item item)
{
	item = item;
}