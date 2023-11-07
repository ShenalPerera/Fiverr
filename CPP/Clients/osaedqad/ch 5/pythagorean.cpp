// Lab 3: pythagorean.cpp
// Find Pythagorean triples using brute force computing.
#include <iostream>
using namespace std;

int main()
{
    int count = 0; // number of triples found
    long int hypotenuseSquared; // hypotenuse squared
    long int sidesSquared; // sum of squares of sides

    long int side1,side2,hypotenuse;

    cout << "Side 1\tSide 2\tSide3" << endl;

    // side1 values range from 1 to 500
    /* Write a for header for side1 */
    for(side1 =1 ; side1<=500; side1++)
    {
        // side2 values range from current side1 to 500
        /* Write a for header for side2 */
        for(side2 = side1; side2 <= 500; side2++)
        {
            // hypotenuse values range from current side2 to 500
            /* Write a for header for hypotenuse */
            for(hypotenuse=side2; hypotenuse<= 500; hypotenuse++)
            {
                // calculate square of hypotenuse value
                /* Write a statement to calculate hypotenuseSquared */
                hypotenuseSquared = hypotenuse * hypotenuse;
                // calculate sum of squares of sides
                /* Write a statement to calculate the sum of the sides Squared */
                sidesSquared = (side1 * side1) + (side2 * side2);
                // if (hypotenuse)^2 = (side1)^2 + (side2)^2,
                // Pythagorean triple
                if ( hypotenuseSquared == sidesSquared )
                {

                    // display triple
                    cout << side1 << '\t' << side2 << '\t'
                    << hypotenuse << '\n';
                    ++count; // update count
                } // end if
            } // end for
        } // end for
    } // end for

    // display total number of triples found
    cout << "A total of " << count << " triples were found." << endl;
} // end main