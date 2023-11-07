#include "Clock.h"
#ifndef CLOCK_CLOCK12_H
#define CLOCK_CLOCK12_H
class Clock12 : public Clock{
protected:
    char state;
public:
    Clock12(int hours,int minutes, int seconds);
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);

    void display();
    void addHours();
//    void addMinutes();
//    void addSeconds();
};
#endif //CLOCK_CLOCK12_H
