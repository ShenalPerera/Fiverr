#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Monster.hpp"
#include "Dragon.hpp"
using namespace std;

int main() {

    Player player1("Test_player",100,0,2,0);
    // Check the player

    // Inventory empty check
    player1.displayStats();
    Location location_test("Dummy location","This dummy description", false, false, false);
    // create item
    Item item1("Test Item 1",potion,100, true,"Give health increase",location_test);

    // check item status
    item1.getDetails();

    // Change the item name, change num of usues
    item1.setName("Test item 1 changed");
    item1.setNumOfUses(90);
    item1.setUsable(false);

    cout << "\n\nCheck changed was affected" << endl;
    item1.getDetails();

    // Make usable
    cout << "\n\nTest make usable will affect to the object" << endl;
    item1.makeUsable();
    item1.getDetails();

    cout << "\n\nCheck the player states again" << endl;
    player1.displayStats();

    cout << "Add the item1 into the inventory" << endl;
    player1.updateStat(item1);

    cout << "\n\nCheck player stats" << endl;
    player1.displayStats();

    cout << "\n\nCheck player attributes" << endl;
    player1.displayAttributes();

    cout << "\n\nCheck player class's , attributes and mutators" << endl;
    player1.setName("Test player changed");
    player1.setHealth(90);
    player1.displayAttributes();

    cout << "\n\nCheck player attrubutes " << endl;
    player1.setHealth(10);
    player1.setAttack(10);
    player1.setDamage(90);
    player1.setDamage(20);

    if (player1.getHealth() == 10 && player1.getAttack() == 10 && player1.getDamage() == 20){
        cout << "Player class function works properly" << endl;
    }
    else{
        cout << "Player class is not working" << endl;
        throw runtime_error("Class is not working properly");
    }

    player1.displayAttributes();


    cout << "\n\nChecking Locations class" << endl;
    // Set initial empty location
    Location location("Dummy location","This dummy description", false, false, false);
    location.displayData();

    // Validate the created object
    if (location.getName() != "Dummy location" || location.getDescription() != "This dummy description"){
        throw runtime_error("location name or the description has error while creating");
    }
    if (location.getHasPlayer() || location.getHasMonster() && location.getHasItem()){
        throw runtime_error("Check the boolean values has error?");
    }

    cout << "\n\nChange the Attributes of the  location" << endl;
    location.setHasItem(true);

    if (!location.getHasItem())
        throw runtime_error("Error in setHasItem() call or getter");

    location.setHasMonster(true);

    if (!location.getHasMonster())
        throw runtime_error("Error in setHasItem() call or getter");

    location.displayData();

    // create neighbouring location for the current location
    Location destination1("Dummy destination 1","This is dummy neighbour for current location", false, false, false);
    Location destination2("Dummy destination 2","This is dummy neighbour for current location", false, true, false);

    cout << "\n\nChecking the add function of neighbouring destination" << endl;
    location.addDestinations(destination1);
    location.addDestinations(destination2);

    if (location.getDestinations().empty())
        throw runtime_error("Adding function may not work properly");
    else
        location.displayData();


    Monster monster1("Monster 1",100,1,destination1,item1);
    Dragon dragon("Name",90,70,location,item1);



    return 0;
}
