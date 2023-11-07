#include <iostream>
#include "Clock12.h"
using namespace std;

Clock12::Clock12(int hours, int minutes, int seconds) : Clock(hours,minutes,seconds){
    this->state = 'A';
}

void Clock12::setHours(int hours) {
    this->hours = hours;

}
void Clock12::setMinutes(int minutes){
    this->minutes = minutes;
}

void Clock12::setSeconds(int seconds) {
    this->seconds =  seconds;
}

void Clock12::addHours() {

    if (this->hours == 11){
        state = (state == 'A') ? 'P' : 'A';
        setHours(12);
    }
    else if (getHours() == 12){
        setHours(1);
    }
    else{
        setHours(getHours() + 1);
    }
}

void Clock12::display() {
    cout << getHours() << endl;
}