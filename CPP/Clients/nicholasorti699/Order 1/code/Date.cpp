#include <iostream>
#include "Date.h"

using namespace std;

// Default constructor set all three attributes to 1
Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 1970;
}

// Initialize the attributes and call the setMonth member function for set the month
Date::Date(int _month, int _day, int _year) {
    setMonth(_month);
    this->year =_year;
    this->day = _day;
}


void Date::setMonth(int _month) {
    // Check the given month is valid range
    if (_month <= 12 && _month >= 1){
        this->month = _month;   // if valid set that month
    }
    else{
        this->month = 1;    // if not set month as 1
    }
}

void Date::setDay(int _day) {
    this->day = _day;
}

void Date::setYear(int _year) {
    this->year = _year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

void Date::displayDate() const{
    cout << month << "/" << day << "/" << year << endl;
}