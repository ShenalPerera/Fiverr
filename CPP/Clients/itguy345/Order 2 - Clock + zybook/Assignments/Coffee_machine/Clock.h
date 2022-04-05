#include <iostream>
#include <time.h>

using namespace std;

#ifndef PART_2_CLOCK_H
#define PART_2_CLOCK_H

class Clock{
private:
    time_t currTimeMillis;
    time_t nextTimeMillies;
    tm* currTime;
    tm* presetTime;
public:
    Clock();
    void displayClock() const;
    void setHour(int hour) const;
    void setMinutes(int min) const;
    tm* getCurrTime();
    tm* getPresetTime();

};

#endif //PART_2_CLOCK_H
