#include <iostream>

#include "Date.h"

using namespace std;

int main() {
    // Create a object from default constructor
    Date default_date;

    // Dismayed the date
    default_date.displayDate();

    // Create custom date object
    Date custom_date(4,26,1998);
    cout << "\nCheck parameterized constructor" << endl;
    custom_date.displayDate();

    // Change the date and month
    cout << "\nChange the date, month and year" << endl;
    custom_date.setDay(2);
    custom_date.setMonth(12);
    custom_date.setYear(1999);
    custom_date.displayDate();

    // Try to give invalid month
    cout << "\nCheck setMethod() functionality" << endl;
    custom_date.setMonth(13);
    custom_date.displayDate();

    cout << "\ncheck the whole testing with get function" << endl;
    cout << "\nNo printing lines if programme is correct" << endl;

    if (custom_date.getYear() != 1999 || custom_date.getMonth() != 1 || custom_date.getDay() != 2){
        cout << "Error fond" << endl;
    }
    return 0;
}
