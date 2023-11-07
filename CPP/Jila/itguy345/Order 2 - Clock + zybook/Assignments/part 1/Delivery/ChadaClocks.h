#include <iostream>
#include <time.h>

using namespace std;

#ifndef CLOCK_CHADACLOCKS_H
#define CLOCK_CHADACLOCKS_H
class ChadaClocks{
    private:
        time_t currTimeMillis;
        tm* currTime;
    public:
        ChadaClocks();
        void displayClocks() const;
        void addHour() const;
        void addMinutes() const;
        void addSeconds() const;

};
#endif //CLOCK_CHADACLOCKS_H
