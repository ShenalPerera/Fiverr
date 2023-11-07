#include <iostream>
#include <string>
#include <cstdlib>
#include "Monster.h"
#include "Player.h"
#include "Location.h"
#include "Item.h"
#include "dragon.h"

using namespace std;

int main()
{
    // Prototype testing for location
    Location location("Rimshow den","This is dummy description", true, true, false);
    location.displayData();
}