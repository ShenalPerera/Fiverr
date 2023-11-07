#pragma once
#include <vector>
#include <string>

class Location
{
private:
    std::string name;
    std::string description;
    bool hasPlayer;
    bool hasItem;
    bool hasMonster;

public:
    Location();
    Location(std::string, std::string, bool, bool, bool);
    void displayData();
    void updateData(std::string, std::string, bool, bool, bool);
    void displayHasPlayer();
    void displayHasMonster();
    void displayHasItem();
};