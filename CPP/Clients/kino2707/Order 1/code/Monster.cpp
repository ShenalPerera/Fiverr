#include <iostream>
#include "Monster.hpp"

Monster::Monster() {
    this->name = "Default name";
    Location location1;
    Item* item1 = new Item("Dummy item",armour,30, true,"Protection", location1);

    this->item = *item1;
    this->defence = 0;
    this->attack = 0;
    this->health = 100;
    this->damage = 0;
    this->level = 1;
    this->location = location1;

}

Monster::Monster(std::string _name, int _health,int _level, Location location1, Item item1) {
    this->name = _name;
    this->health = _health;
    this->level = _level;
    this->location = location1;
    this->item = item1;
}

void Monster::assignItem(Item item1) {
    this->item = item1;
}

void Monster::placeLocation(Location location1) {
    this->location = location1;
}

void Monster::getDetails() const {
    cout << "Monster " << name << "has " << health << " health" << endl;
}
int Monster::getAttack() {
    this->health -= 10;
}