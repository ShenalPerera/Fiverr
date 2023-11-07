// Lab 2: AsteriskTriangles.cpp
// Draw four triangles composed of asterisks.

#include <iostream>
using namespace std;

int main()
{
    int row; // the row position
    int column; // the column position
    int space; // number of spaces to print

    // first triangle
    /* Write a for header to iterate row from 1 to 10 */
    for(row=1; row <= 10; row++)
    {
    /* Write a for header to iterate column from 1 to row */
        for(column = 1; column<= row;column++)
            cout << "*";

        cout << endl;
    } // end for

    cout << endl;

    // second triangle
    /* Write a for header to iterate row from 10 down to 1 */
    for(row = 10; row >=1; row--)
    {
    /* Write a for header to iterate column from 1 to row */
        for(column = 1; column<= row; column++)
            cout << "*";

        cout << endl;
    } // end for

    cout << endl;

    // third triangle
    /* Write a for header to iterate row from 10 down to 1 */
    for(row = 10; row>=1; row--)
    {
    /* Write a for header to iterate space from 10 down to one more than row */
        for(space=10; space >= row+1; space--)
            cout << " ";

    /* Write a for header to iterate column from 1 to row */
        for(column=1; column<= row; column++)
            cout << "*";

    cout << endl;
    } // end for

    cout << endl;

    // fourth triangle
    /* Write a for header to iterate row from 10 down to 1 */
    for(row=10; row>=1; row--)
    {
    /* Write a for header to iterate space from 1 to one less than row */
        for(space=1; space<= row-1; space++)
            cout << " ";

    /* Write a for header to iterate column from 10 down to row */
        for(column=10; column>= row; column--)
            cout << "*";

        cout << endl;
    } // end for
} // end main
