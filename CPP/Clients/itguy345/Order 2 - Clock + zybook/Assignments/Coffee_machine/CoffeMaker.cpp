#include <iostream>
#include "Clock.h"
#include "Menu.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void makeCoffee(){
    cout << "boiling water..." << endl;
    sleep(5);
    cout << "Mixing..." << endl;
    sleep(3);
}


int main(){
//    Clock clock1;
//    clock1.displayClock();


    Menu menu;
    menu.displayMenu();
    int water = 0;
    int coffee = 0;
    cout << "Enter the water  : ";
    cin >> water;

    cout << "Enter the coffee : ";
    cin >> coffee;
    int userInput;

    while (water != 0 && coffee != 0){
        Clock clock1;

        system("clear");

        clock1.displayClock();
        menu.displayMenu();

        cin >> userInput;
        int hours;
        int minutes;
        cout << "brewing coffee..." << endl;
        if (userInput == 1){
            cout << "brewing coffee..." << endl;
            sleep(2);
            makeCoffee();
            cout << "filling..." << endl;
            sleep(1);
            water -= 5;
            coffee -=2;

        }
        if ( userInput == 11){



            cout << "Set the hours (1 - 12) : ";
            cin >> hours;

            cout << "Set the hours (1 - 59) : ";
            cin >> minutes;

            cin >> userInput;

            if (userInput == 1){

                system("clear");

                continue;
            }

        }

        if (userInput == 2){
            system("clear");
            clock1.displayClock();
        }

        if (userInput == 3){
            int second = 0;


            int nextHour = clock1.getPresetTime()->tm_hour;
            int nextMinute = clock1.getPresetTime()->tm_min;
            system("clear");
            cout << "waiting" << endl;
            while(!((hours - nextHour) == 0 && (minutes - nextMinute) == 0)){

                sleep(1);

                second++;

                if (second == 60){
                    nextMinute +=1;
                    if (nextMinute == 60){
                        nextHour += 1;
                        clock1.setMinutes(nextMinute);
                        nextMinute = 0;
                        if (nextHour == 24){
                            nextMinute = 0;
                            clock1.setHour(nextHour);
                        }
                    }
                }
                cout <<"."<<flush ;
                if (second % 60 == 0){
                    system("clear");
                    cout << "waiting" << endl;
                }


            }
            cout << "Wakes up" << endl;

            menu.displayMenu();
            cin >> userInput;

        }
        if (userInput == 4){
            break;
        }
        menu.displayMenu();

    }
    if (water == 0){
        cout <<"Water runs out!" << endl;
    }
    return 0;
}