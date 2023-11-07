#ifndef CLION_MAIN_HPP
#define CLION_MAIN_HPP
#include <string>
#include "Player.hpp"
#include "Monster.hpp"

using namespace std;
// Function to read the rules and display
void displayRules(string filename);

// Function to create a player when name is given
Player createPlayer(string name);

void setDamage(Player&);

// Create the base game map
vector<Location> createMap();

void setDestinations(int location1,int location2, int location3, Location &current, vector<Location> &map);

// give true and false according to the given probability out of 100
bool generateProb(int value_out_hundred);

// create monsters
void assignMonstersAndItems(vector<Location> &map,Monster monsters_map[],Item items_map[]);


//create random integer from in to out
int randInt(int in, int out);

// Move through the map
void move(vector<Location> &map,Player &);

// Show map
void show_map(vector<Location> &map);

Location * current_location(vector<Location> &map);

void attack(vector<Location> & map,Monster monsters[]);

void attack(vector<Location> & map,Monster monsters[],Player &player);

void flee(vector<Location> &map,Monster monsters[],Player &player);

void examine(vector<Location> &map,Player &player, Item items[]);

void handle_inventory(vector<Location> &map,char take_drop,Player &player,Item items[]);

void consumeOil(Player &player);

void update_inventory(Player & player);

void update_player(Player &player);

bool game_status(vector<Location> &map,Player &player);

void drink_potion(Player &player);
#endif //CLION_MAIN_HPP
