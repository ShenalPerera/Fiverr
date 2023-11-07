#include"Player.h"
#include<iostream>
#include<cstdlib>
#include <vector>
#include <string>

using namespace std;

Player::Player(string name)
{
    name = name;
	health = (rand() % 9 + 4) + 12;
	attack = health / 6;
	defence = attack / 2;
	damage = attack/3 + 0;
    luck = (rand() % 4 + 2);
    Item map = new Item("Map", item, 1000000000, "");
    Item lantern = new Item("Lantern", item, 130, "Lights way losing 2-5 points with each move or search action. Allow a realistic number of turns for the player to complete the quest");
    Item sword = new Item("Sword", weapon, 1, "adds +2 damage to user’s current damage");
    Item provisions = new Item("Provisions", item, 3, "Each provision restores 5-10 health");
    inventory.push_back(map);
    inventory.push_back(lantern);
    inventory.push_back(sword);
    inventory.push_back(provisions);
}

void Player::updateStats(Item item)
{   
    if(inventory.size() == 12){
        inventory.pop_back();
        inventory.push_back(item);
    }else{
        inventory.push_back(item);
    }
	
}

void Player::displayStats()
{
	for(Item item : inventory){
        cout << item << " ";
    }
		
}

void Player::updateAtribute(int health, int attack, int luck)
{
	health = health;
	damage += attack/3;
	luck = luck;
}

void Player::displayAttribute()
{
	cout << health << endl <<
		attack << endl <<
		defence << endl <<
		damage << endl <<
		luck << endl;
}