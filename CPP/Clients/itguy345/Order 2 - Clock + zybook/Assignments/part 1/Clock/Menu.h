#include "ChadaClocks.h"
#ifndef CLOCK_MENU_H
#define CLOCK_MENU_H


class Menu {
    private:
        int userInput;
        ChadaClocks chadaClocks;
    public:
        Menu();
        void displayMenu();
        void getInput();
        void addAutoSeconds() const;
};


#endif //CLOCK_MENU_H
