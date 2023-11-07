// Lab 1: customerCredit.cpp
// Create Credit object and invoke its calculateBalance function.
#include <iostream>
#include <iomanip> // parameterized stream manipulators
using namespace std;

int main()
{
    int account; // account number
    /* Write declarations for four double variables:
    balance, charges, credits and creditLimit */
    double balance;
    double charges;
    double credits;
    double creditLimit;

    cout << "Enter account number (-1 to end): ";
    /* Write code to read the customer's account number */
    cin >> account;
    // set floating-point number format
    /* Write code to use the stream manipulators fixed and
    setprecision to set the floating-point number format */

    // exit if the input is -1 otherwise, proceed with the program
    /* Write a while loop with a condition that tests for the sentinel value */
    while (account != -1)
    {

            /* Write code to prompt for and input the customer's balance */
            cout << "Enter beginning balance: ";
            cin >> balance;
            /* Write code to prompt for and input the customer's charges */
            cout << "Enter total charges: ";
            cin >> charges;
            /* Write code to prompt for and input the customer's credits */
            cout << "Enter total credits: ";
            cin >> credits;
            /* Write code to prompt for and input the customer's credit limit */
            cout << "Enter the credit limit: ";
            cin >> creditLimit;
            // calculate and display new balance
            /* Write a statement to calculate the customer's new balance */
            balance = balance +  charges -credits;
            /* Display the new balance */
            cout << "New balance is " <<setprecision(2) << fixed<< balance;
            // display a warning if the user has exceed the credit limit
            /* Write an if statement to determine whether the credit limit is exceeded */
            /* Display a message if the credit limit was exceeded */

            if (balance > creditLimit){
                cout << "\nAccount:      " <<  account << setw(5) << endl;
                cout << "Credit Limit: " <<setprecision(2) << fixed<< creditLimit << setw(5) << endl;
                cout << "Balance:      " <<setprecision(2) << fixed<<  balance << setw(5) << endl;
                cout << "Credit Limit Exceeded.\n" << endl;
            }

            cout << "\n\nEnter Account Number (or -1 to quit): ";
            /* Write code to input the next account number */
            cin >> account;
    } // end while
} // end main