#include <iostream>
#include "Monster.hpp"

Monster::Monster() {
    this->name = "Empty";
    Location location1;
    Item  item1("Dummy item",armour,30, true,"Protection", location1);

    this->item = item1;
    this->defence = 0;
    this->attack = 0;
    this->health = 100;
    this->damage = 0;
    this->level = 1;
    this->location = location1;

}

Monster::Monster(const Monster &monster) {
    name = monster.name;
    level = monster.level;
    health = monster.health;
    attack = monster.attack;
    defence = monster.defence;
    damage = monster.damage;
    location = monster.location;
    item = monster.item;
}


Monster::Monster(std::string _name, int _level,int _health,int _attack,int _defence,int _damage,Location location1, Item item1) {
    this->name = _name;
    this->health = _health;
    this->level = _level;
    this->location = location1;
    this->item = item1;
    this->attack = _attack;
    this->defence = _defence;
    this->damage = _damage;

}

void Monster::assignItem(Item &item1) {
    this->item = item1;
}

void Monster::placeLocation(Location &location1) {
    this->location = location1;
}

void Monster::getDetails() const {
    cout << "Monster : " << name <<"("<<level<< ")\n\thealth : " << health << "\n\tattack : " << attack<<"\n\tdefence : "<< defence<<
    "\n\tdamage : " << damage <<
    endl;
}


void Monster::setName(std::string _name) {
    name = _name;
}

void Monster::setLevel(int level_) {
    level = level_;
}

void Monster::setHealth(int health_) {
    this->health = health_;
}

void Monster::setAttack(int attack_) {
    this->attack = attack_;
}

void Monster::setDefence(int defence_) {
    this->defence = defence_;
}

void Monster::setDamage(int damage_) {
    this->damage = damage_;
}

string Monster::getName() const {
    return name;
}

int Monster::getLevel() const {
    return level;
}

int Monster::getHealth() const {
    return health;
}

int Monster::getDefence() const {
    return defence;
}

int Monster::getDamage() const {
    return damage;
}

int Monster::getAttack() const{
    return this->attack;
}


