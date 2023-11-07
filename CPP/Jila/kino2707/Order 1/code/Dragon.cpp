#include <iostream>
#include "Dragon.hpp"
#include "Monster.hpp"

Dragon::Dragon() = default;;

Dragon::Dragon(string _name, int _health, int _level, Location location1, Item item1): Monster(_name,_health,_level,location1,item1) {

}

void Dragon::displayDragon() {
    this->getDetails();
}
