#ifndef CODE_LOCATION_HPP
#define CODE_LOCATION_HPP
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
public:
    Location();
    Location(std::string, std::string, bool, bool, bool);

    // Actuators
    void setName(string _name);
    void setDescription(string _description);
    void setHasPlayer(bool _hasPlayer);
    void setHasItem(bool _hasItem);
    bool setHasMonster(bool _hasMonster);

    // Mutators
    string getName() const;
    string getDescription() const;
    vector<Location> getDestinations() const;
    bool getHasPlayer() const;
    bool getHasItem() const;
    bool getHasMonster() const;

    void displayData();
    void updateData(std::string, std::string, bool, bool, bool);
    void addDestinations(Location location);
};


#endif //CODE_LOCATION_HPP
