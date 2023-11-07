// Lab 2: reverse.cpp
// Reverse the digits of a number.
#include <iostream>
#include <iomanip>
using namespace std;

/* Write prototype for reverseDigits */
int reverseDigits(int);
int main()
{
    int number; // input number

    cout << "Enter a number between 1 and 9999: ";
    cin >> number;

    cout << "The number with its digits reversed is: ";

    // find number with digits reversed
    cout << /* Write call to reverseDigits */reverseDigits(number)<< endl;
} // end main

// reverseDigits returns number obtained by reversing digits of n
/* Write function header for reverseDigits */
int reverseDigits(int n)
{
    int reverse = 0; // reversed number
    int divisor = 1000; // current divisor
    int multiplier = 1; // current multiplier

    // loop until single-digit number
    while ( n > 9 )
    {
        // if n >= current divisor, determine digit
        if ( n >= divisor )
        {
            // update reversed number with current digit
            reverse += n / divisor * multiplier;
            n %= divisor; // update n
            /* Write a line of code that reduces divisor by a factor of 10 */
            divisor = divisor / 10;
            /* Write a line of code that increases multiplier by a factor of 10 */
            multiplier = multiplier * 10;
        } // end if
        else // else, no digit
            divisor /= 10; // update divisor
    } // end while

    reverse += n * multiplier;
    return reverse; // return reversed number
} // end function reverseDigits