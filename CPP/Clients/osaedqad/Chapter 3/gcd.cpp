// Lab 3: gcd.cpp
// Finds greatest common divisor (GCD) of 2 inputs.
#include <iostream>
using namespace std;

/* Write prototype for gcd */
int gcd(int,int);
int main()
{
    int a; // first number
    int b; // second number

    // loop for 5 pairs of inputs
for ( int j = 1; j <= 5; j++ )
{
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "The greatest common divisor of "
    << a << " and " << b << " is ";

    // find greatest common divisor of a and b
    cout << /* Write call for gdc */gcd(a,b) << endl;
    } // end for
} // end main

// gcd finds greatest common divisor of x and y
/* Write header for gcd */
int gcd(int x, int y)
{
    int greatest = 1; // current greatest common divisor, 1 is minimum

    // loop from 2 to smaller of x and y
    for ( int i = 2; i <= ( ( x < y ) ? x : y ); i++ )
    {
        // if current i divides both x and y
        if ( /* Write condition to determine if both x and y are
        divisible by i */ x % i == 0 && y % i ==0)
            greatest = i; // update greatest common divisor
    } // end for

    /* Write a statement to return greatest */
    return greatest;
} // end function gcd
