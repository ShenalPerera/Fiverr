#include <iostream>

#include "Location.hpp"
#include "Item.hpp"

using namespace std;

Location::Location() {
    this->name = "Default Location";
    this->description = "Default description";
    this->hasItem = false;
    this->hasMonster = false;
    this->hasPlayer = false;
}

Location::Location(string _name, string _description, bool _hasItem, bool _hasPlayer, bool _hasMonster) {
    this->name = _name;
    this->description = _description;
    this->hasItem = _hasItem;
    this->hasPlayer = _hasPlayer;
    this->hasMonster = _hasMonster;
}

void Location::setName(string _name) {
    this->name = _name;
}

void Location::setDescription(string _description) {
    this->description = _description;
}

void Location::setHasItem(bool _hasItem) {
    this->hasItem = _hasItem;
}

bool Location::setHasMonster(bool _hasMonster) {
    this->hasMonster = _hasMonster;
}

void Location::setHasPlayer(bool _hasPlayer) {
    this->hasPlayer = _hasPlayer;
}

string Location::getName() const {
    return name;
}

string Location::getDescription() const {
    return description;
}

vector<Location> Location::getDestinations() const {
    return destination;
}

bool Location::getHasItem() const {
    return hasItem;
}

bool Location::getHasMonster() const {
    return hasMonster;
}

bool Location::getHasPlayer() const {
    return hasPlayer;
}

void Location::displayData() {
    cout << name << " ";

    if (hasPlayer)
        cout << "has a player ";
    if (hasMonster)
        cout << "has a Monster ";
    if (hasItem)
        cout << "Has a Item ";
    else if ( !hasItem || !hasMonster || !hasPlayer)
        cout << "is empty";

    cout << endl;

    if (!destination.empty()){
        cout << "Neighbour Destinations :" << endl;

        for (auto & i : destination) {
            cout <<"                        " <<i.name << endl;
        }
    }

}

void Location::updateData(string _name, string _description, bool _hasItem, bool _hasMonster, bool _hasPlayer) {
    setName(_name);
    setDescription(_description);
    setHasPlayer(_hasPlayer);
    setHasMonster(_hasMonster);
    setHasItem(_hasItem);
}

void Location::addDestinations(Location location) {
    this->destination.push_back(location);
}