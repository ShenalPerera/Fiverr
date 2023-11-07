#include <iostream>
#include "Player.hpp"
#include <string>

Player::Player() {
    this->name = "player";
    this->health = 100;
    this->damage = 0;
    this->attack = 1;
    this->defence = 0;
    this->luck = 0;
}

Player::Player(string name, int health, int damage,int attack,int defence) {
    this->name = name;
    this->damage = damage;
    this->health = health;
    this->attack = attack;
    this->defence = defence;
    this->luck = 0;
    this->art_count = 0;
}

void Player::setName(string _name) {
    this->name = _name;
}

void Player::setHealth(int _health) {
    this->health = _health;
}

void Player::setArtCount() {
    this->art_count++;
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

void Player::setLuck(int _luck) {
    this->luck = _luck;
}

void Player::addItem(Item item1) {
    if (inventory.size() < 20){
        inventory.push_back(item1);
    }
    else{
        cout << "Inventory is full" << endl;
    }

}

string Player::getName() const {
    return this->name;
}

int Player::getHealth() const {
    return this->health;
}

int Player::getArtCount() const {
    return this->art_count;
}

int Player::getDamage() const {
    return this->damage;
}

vector<Item> Player::getInventory() const {
    return this->inventory;
}

int Player::getAttack() const {
    return attack;
}

int Player::getDefence() const {
    return defence;
}

int Player::getLuck() const {
    return luck;
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
    cout << "| Player : " << name << " | " << "Health : " << health << " | " << "Attack : "<< attack <<
    " | "<< "Defence : "<< defence << " | " << "Damage : " << damage << " |" <<
    endl;
}

void Player::updateAttribute(int index, int value) {
    int val = inventory.at(index).getNumOfUses();

    inventory.at(index).setNumOfUses(--val);
    health += value;
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

void Player::removeItem() {
    int input;
    for (int i = 0; i < inventory.size(); ++i) {
        cout << i+1 << " - " << inventory.at(i).getName() << endl;
    }

    cin >> input;
    inventory.erase(inventory.begin() + input - 1);
}

void Player::consumeOil(int amount) {
    int temp = inventory.at(2).getNumOfUses();
    inventory.at(2).setNumOfUses(temp-amount);
}

void Player::updateInventory() {
    for (int i = 3; i < inventory.size(); ++i) {
        if (inventory.at(i).getName() == "Lantern"){
            consumeOil(- 1 * inventory.at(i).getNumOfUses());
        }
    }



}