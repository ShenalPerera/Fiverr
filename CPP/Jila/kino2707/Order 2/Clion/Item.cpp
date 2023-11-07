#include <iostream>

#include "Item.hpp"

using namespace std;

Item::Item() {
    this->name = "Default item name";
    this->isUsable = false;
    this->itemType = item;
    this->numOfUses = 0;
}

Item::Item(string _name, ItemType itemType, int _amount, bool isUsable, string effect,Location location1) {
    this->name = _name;
    this->itemType = itemType;
    this->numOfUses = _amount;
    this->isUsable = isUsable;
    this->specialEffects = effect;
    this->location = location1;
}

void Item::setName(string _name) {
    this->name = _name;
}

void Item::setItemType(ItemType itemType1) {
    this->itemType = itemType1;
}

void Item::setNumOfUses(int num) {
    this->numOfUses = num;
}

void Item::setUsable(bool status) {
    this->isUsable = status;
}

void Item::setEffect(string effect) {
    this->specialEffects = effect;
}

void Item::setLocation(Location location1) {
    this->location = location1;
}

string Item::getName() const {
    return name;
}

ItemType Item::getItemType() const {
    return itemType;
}

int Item::getNumOfUses() const {
    return numOfUses;
}

string Item::getEffect() const {
    return specialEffects;
}

bool Item::getIsUsable() const {
    return isUsable;
}

Location Item::getLocation() const {
    return location;
}

void Item::makeUsable() {
    if (numOfUses <= 0 ){
        this->isUsable = false;
    }
    else{
        isUsable = true;
    }
}

void Item::getDetails() const {
    if (isUsable)
        cout << "Item " << name << " | " << " Number of uses : " << numOfUses << endl;
    else
        cout << "Item " << name << " | " << " Number of uses : " << numOfUses << " Not usable item" << endl;

    cout << " in the " << location.getName() << endl;
}