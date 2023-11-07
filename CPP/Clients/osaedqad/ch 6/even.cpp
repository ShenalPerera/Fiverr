// Lab 1: even.cpp
// Determine whether inputs are odd or even.
#include <iostream>
using namespace std;

/* Write a function prototype for function even, which takes an int parameter
and returns a bool */
bool isEven(int);

int main()
{
    int x; // current input

    // loop for 3 inputs
    for ( int i = 1; i <= 3; i++ )
    {
        cout << "Enter an integer: ";
        cin >> x;

    // determine if input is even
        if (isEven(x) )
            cout << x << " is an even integer\n\n";
        else
            cout << x << " is an odd integer\n\n";
    } // end for

    cout << endl;
} // end main

/* Define function even. Use the modulus operator to determine if an integer
 is evenly divisible by two. */
bool isEven(int number){
    return number % 2 == 0;
}