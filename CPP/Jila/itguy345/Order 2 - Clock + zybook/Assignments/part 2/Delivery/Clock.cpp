#include <iostream>
#include "Clock.h"

Clock::Clock() {
    this->currTimeMillis = time(nullptr);
    this->nextTimeMillies = time(0);
    this->currTime = localtime(&currTimeMillis);
    this->presetTime = localtime(&nextTimeMillies);
}

void Clock::displayClock() const {
    char stringBuffer[80];
    cout << "*************************" << endl;
    cout << "*     24-Hour-Clock     *" << endl;
    strftime (stringBuffer, 80, "*      %H:%M %p         *", this->currTime);
    cout << stringBuffer << endl;
    cout << "*************************" << endl;
}

void Clock::setHour(int hour) const {
    if (hour >= 0 && hour <= 23){
        this->presetTime->tm_hour = hour;
    }
    else{
        cout << "Invalid Input for hours" << endl;
    }
}

void Clock::setMinutes(int min) const {
    if (min >= 1 && min <= 59){
        this->presetTime->tm_min = min;
    }
    else{
        cout << "Invalid input for minutes" << endl;
    }
}

tm *Clock::getCurrTime() {

    return this->currTime;
}

tm *Clock::getPresetTime() {
    return this->presetTime;
}