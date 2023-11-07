// Lab 2: Payroll.cpp
// Calculate wages for a payroll.
#include <iostream>
#include <iomanip> // parameterized stream manipulators
using namespace std;

int main()
{
    /* Write declarations for hours, rate and salary */
    double hours;
    double rate;
    // processing phase
    // get first employee's hours worked
    cout << "Enter hours worked (-1 to end): ";
    cin >> hours;

    // set floating-point number format
    /* Write code to use the stream manipulators fixed and
    setprecision to set the floating-point number format */
    cout.precision(2);
    // loop until sentinel value read from user
    /* Write the while loop */
    while ( hours != -1)
    {
        // get hourly rate
        /* Write code to prompt for and input hourly rate */
        cout << "Enter hourly rate of the worker ($00.00): ";
        cin >> rate;
        // if employee worked less than 40 hours
        /* Write code to determine whether hours worked was
        less than or equal to 40 and if so, calculate
        base pay. If not, calculate base + overtime pay */
        double salary;
        if (hours <= 40){
            salary = hours * rate;
        }
        else{
            salary = 40 * rate + (hours - 40) * 1.5 * rate;
        }
        /* Write code to display the salary */
        cout << "salary is $" << fixed << salary;
        // prompt for next employee's data
        cout << "\n\nEnter hours worked (-1 to end): ";
        cin >> hours;
    } // end while
} // end main