#include <iostream>
#include <string>
#include "Clock.h"

using namespace std;



Clock::Clock(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

int Clock::getHours() {
    return this->hours;
}

int Clock::getMinutes() {
    return this->minutes;
}

int Clock::getSeconds() {
    return this->seconds;
}
