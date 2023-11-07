// This is the header file of the Date class

#ifndef CODE_DATE_H
#define CODE_DATE_H


class Date {
    // Dat members
private:
    int month;
    int day;
    int year;

public:
    // Default constructor
    Date();

    // Parameterized constructor
    Date(int _month, int _day, int _year);

    // setters
    void setMonth(int _month);
    void setDay(int _day);
    void setYear(int _year);

    // Getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Display
    void displayDate() const;
};


#endif //CODE_DATE_H
