#include <iostream>
#include "Dragon.hpp"
#include "Monster.hpp"

Dragon::Dragon() = default;;

Dragon::Dragon(std::string _name, int _level,int _health,int _attack,int _defence,int _damage,Location location1, Item item1): Monster(_name,_level,_health,_attack,_defence,_damage,location1,item1) {

}

void Dragon::displayDragon() {
    this->getDetails();
}
