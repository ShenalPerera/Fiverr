#include <iostream>
#include "Player.hpp"
#include <string>

Player::Player() {
    this->name = "player";
    this->health = 100;
    this->damage = 0;
    this->attack = 1;
    this->defence = 0;
}

Player::Player(string name, int health, int damage,int attack,int defence) {
    this->name = name;
    this->damage = damage;
    this->health = health;
    this->attack = attack;
    this->defence = defence;
}

void Player::setName(string _name) {
    this->name = _name;
}

void Player::setHealth(int _health) {
    this->health = _health;
}

void Player::setDamage(int _damage) {
    this->damage = _damage;
}

void Player::setAttack(int _attack) {
    this->attack = _attack;
}

void Player::setDefence(int _defence) {
    this->defence = _defence;
}

void Player::addItem(Item item1) {
    inventory.push_back(item1);
}

string Player::getName() const {
    return this->name;
}

int Player::getHealth() const {
    return this->health;
}

int Player::getDamage() const {
    return this->damage;
}

int Player::getAttack() const {
    return attack;
}

int Player::getDefence() const {
    return defence;
}

void Player::displayStats() const {
    if (inventory.empty()){
        cout << "Inventory is empty" << endl;
    }
    else{
        for (const auto & i : inventory) {
            i.getDetails();
        }
    }

}

void Player::displayAttributes() const {
    cout << "| Player : " << name << " | " << "Health : " << health << " | " << endl;
}

void Player::updateAttribute(int _health, int _damage) {
    setDamage(_damage);
    setHealth(_health);
}

void Player::updateStat(Item item1) {
    if (inventory.size() == 12){
        inventory.pop_back();
        inventory.push_back(item1);
    }
    else{
        inventory.push_back(item1);
    }
}