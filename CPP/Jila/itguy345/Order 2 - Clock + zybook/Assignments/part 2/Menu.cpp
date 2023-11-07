#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu() {}

void Menu::displayMenu() {
    cout << "               *************************" << endl;
    cout << "               *  1 - ON               *" << endl;
    cout << "               *  2 - OFF              *" << endl;
    cout << "               *  3 - PROGRAM          *" << endl;
    cout << "               *************************" << endl;
}