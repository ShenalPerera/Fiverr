// Lab 3: Asterisks.cpp
// Draw a square of asterisks.
#include <iostream>
using namespace std;

int main()
{
    int stars; // number of stars on a side
    int column; // the current column of the square being printed
    int row = 1; // the current row of the square being printed

    // prompt and read the length of the side from the user
    cout << "Enter length of side: ";
    cin >> stars;

    // valid input, if invalid, set to default
    /* Write an if statement to test whether stars is less than 1 */
    if (stars < 1)
    {
        stars = 1;
        cout << "Invalid Input\nUsing default value 1\n";
    } // end if
    /* Write an else if statement to test whether stars is greater than 20 */
    else if (stars > 20){
        stars = 20;
        cout << "Invalid Input\nUsing default value 20\n";
    } // end else if

    // repeat for as many rows as the user entered
    /* Write a while statement to count rows */
    while (row <= stars)
    {
        column = 1;

        // and for as many columns as rows
        /* Write a while statement to count columns */
        while (column <= stars)
        {
            /* Write a series of if, else if, ... statements to
            determine whether an asterisk or a space should be displayed
            at this position in the square */
            if (column == 1 ){
                cout << "*";
            }
            else if(column == stars){
                cout << "*";
            }
            else if (row == 1){
                cout << "*";
            }
            else if (row == stars){
                cout << "*";
            }
            else{
                cout << " ";
            }
            column++;
            /* Increment the column counter */
        } // end inner while

        cout << endl;
        row++;
        /* Increment the row counter */
    } // end outer while
} // end main