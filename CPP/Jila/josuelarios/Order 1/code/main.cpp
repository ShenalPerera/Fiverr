#include <iostream>

using namespace std;

// Menu function
int menu(){
    // Gold the user input
    int option;

    do {
        // output thr message to user
        cout << "Select your option:\n1. Convert from inches to feet\n2. Convert from feet to inches\n3. Exit." << endl;
        cin >> option;

        // Validate the user input
        if (option <=3 && option >=1){
            return option;
        }

        // show error message for the
        cout << "Invalid input !" << endl;
    } while (true);
}

// Feet to inches function
float feetToInches(float feet){
    return feet * 12;
}

// Inches to feet function
float inchesToFeet(float inches){
    return inches / 12;
}

int main() {

    // Run the program
    int user_input;

    // value from the user
    float value;
    do {
        // get the option from the menu function
        user_input = menu();

        // if the option is call the feet to inches function
        if (user_input == 1){
            cout << "Enter the number of feet : ";
            cin >> value;

            cout << "Number of inches : " << feetToInches(value) << endl;
        }

        // handle the inches to feet function
        else if (user_input == 2){
            cout << "Enter the number of inches : ";
            cin >> value;

            cout << "Number of feet : " << inchesToFeet(value) << endl;
        }


    } while (user_input != 3);  // exit condition

    return 0;
}
