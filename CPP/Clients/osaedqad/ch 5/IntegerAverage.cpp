// Lab 1: IntegerAverage.cpp
// Calculate the average of several integers.

#include <iostream>
using namespace std;

int main()
{
    int value; // current value
    int count = 0; // number of inputs
    int total; // sum of inputs

    // prompt for input
    cout << "Enter integers (9999 to end):" << endl;
    cin >> value;

    // loop until sentinel value read from user
    /* Write a for header to initialize total to 0
    and loop until value equals 9999 */
    for (total = 0; value != 9999;count++)
    {
        /* Write a statement to add value to total */
        /* Write a statement to increment count */
        total = total + value;
        cin >> value; // read in next value
    } // end for

// if user entered at least one value
    if ( count != 0 )
        cout << "\nThe average is: "
    << /* Convert total to a double and divide it by count */ (double )total/count << endl;
    else
        cout << "\nNo values were entered." << endl;
} // end main