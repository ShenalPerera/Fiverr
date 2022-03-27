#include <iostream>
#include "Menu.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

Menu::Menu() {}

void Menu::displayMenu() {
    cout << "               *************************" << endl;
    cout << "               *  1 - Add One Hour     *" << endl;
    cout << "               *  2 - Add One Minute   *" << endl;
    cout << "               *  3 - Add One Second   *" << endl;
    cout << "               *  4 - Exit Program     *" << endl;
    cout << "               *************************" << endl;
}

void Menu::addAutoSeconds() const{
    system("clear");
    this->chadaClocks.displayClocks();
    this->chadaClocks.addSeconds();
    sleep(1);
    system("clear");
}

void Menu::getInput() {
    do{
        addAutoSeconds();
        this->displayMenu();
        cin >> this->userInput;
        cin.clear();

        switch(userInput) {
            case 1:
                this->chadaClocks.addHour();

                system("clear");
                break;
            case 2:
                this->chadaClocks.addMinutes();

                system("clear");
                break;
            case 3:
                this->chadaClocks.addSeconds();

                system("clear");
                break;
            case 4:
                cout << "Goodbye." << endl;
                exit(0);
            default:
                cout << "Invalid input!  Please try again." << endl;
                system("clear");
        }

    } while (this->userInput != 4);
}