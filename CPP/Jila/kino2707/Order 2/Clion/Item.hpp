#ifndef CODE_ITEM_HPP
#define CODE_ITEM_HPP
#include <string>
#include "Location.hpp"
using namespace std;

enum ItemType
{
    artefact,
    potion,
    weapon,
    armour,
    item
};

class Item {
private:
    string name;
    ItemType itemType;
    int numOfUses;
    bool isUsable;
    string specialEffects;
    Location location;
public:
    Item();
    Item(string _name, ItemType itemType,int _amount,bool isUsable, string effect, Location location1);

    // Actuators
    void setName(string _name);
    void setItemType(ItemType itemType1);
    void setNumOfUses(int num);
    void setUsable(bool status);
    void setEffect(string effect);
    void setLocation(Location location1);

    // Mutators
    string getName() const;
    ItemType getItemType() const;
    int getNumOfUses() const;
    bool getIsUsable() const;
    string getEffect() const;
    Location getLocation() const;
    void makeUsable();
    void getDetails() const;
};


#endif //CODE_ITEM_HPP
