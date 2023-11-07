#ifndef CLION_LOCATION_HPP
#define CLION_LOCATION_HPP
#include <string>
#include <vector>


using namespace std;

class Location {
private:
    string name;
    string description;
    vector<Location> destination;
    bool hasPlayer;
    bool hasItem;
    bool hasMonster;
    int index;

public:
    Location();
    Location(std::string, std::string, bool, bool, bool);
    ~Location();
    // Actuators
    void setName(string _name);
    void setDescription(string _description);
    void setHasPlayer(bool _hasPlayer);
    void setHasItem(bool _hasItem);
    void setHasMonster(bool _hasMonster);
    void setIndex(int index_);
    // Mutators
    string getName() const;
    string getDescription() const;
    vector<Location> getDestinations() const;
    bool getHasPlayer() const;
    bool getHasItem() const;
    bool getHasMonster() const;
    int getIndex() const;


    void displayData();
    void updateData(std::string, std::string, bool, bool, bool);
    void addDestinations(Location location);
};


#endif //CLION_LOCATION_HPP
