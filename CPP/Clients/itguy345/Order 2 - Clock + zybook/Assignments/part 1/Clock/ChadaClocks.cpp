#include <iostream>
#include "time.h"
#include "ChadaClocks.h"
#include "stdafx.h "

// Initialize the currTime in milliseconds when the constructor is called
ChadaClocks::ChadaClocks() {
    this->currTimeMillis = time(nullptr);
    this->currTime = localtime_s(&currTimeMillis);
}

void ChadaClocks::displayClocks() const{
    char stringBuffer[80];
    cout << "*************************     *************************" << endl;
    cout << "*     12-Hour-Clock     *     *     24-Hour-Clock     *" << endl;
    strftime (stringBuffer, 80, "*      %I:%M:%S %p      *     *      %H:%M:%S %p      *", this->currTime);
    cout << stringBuffer << endl;
    cout << "*************************     *************************" << endl;

}

void ChadaClocks::addHour() const{
    if (this->currTime->tm_hour < 23){
        this->currTime->tm_hour += 1;
    }
    else{
        this->currTime->tm_hour = 0;
    }
}

void ChadaClocks::addMinutes() const{
    if (this->currTime->tm_min < 59 ){
        this->currTime->tm_min +=1;
    }
    else{
        this->currTime->tm_min = 0;
        this->addHour();
    }
}

void ChadaClocks::addSeconds() const {
    if (this->currTime->tm_sec < 59){
        this->currTime->tm_sec += 1;
    }
    else{
        this->currTime->tm_sec = 0;
        this->addMinutes();
    }
}