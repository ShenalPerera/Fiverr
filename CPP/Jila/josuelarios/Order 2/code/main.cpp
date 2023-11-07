#include <iostream>

using namespace std;

// Function to print the Number of Is
void print_I(int count){
    for (int i = 0; i < count; ++i) {
        cout << "I";
    }
}

int main() {
    // To hold the user given number
    int user_input;

    // prompt the user a message
    cout << "Enter a number [1, 10] : ";
    cin >> user_input;

    // Validate the range of the given number
    if (user_input <= 10 && user_input >= 1){
        cout << "Roman Numeral : " ;

        // Handle each case

        if (user_input == 1 || user_input == 2 || user_input == 3){
            print_I(user_input);
        }
        else if (user_input == 4){
            cout << "IV";
        }

        else if (user_input == 5 || user_input == 6 || user_input == 7 || user_input == 8){
            cout << "V";
            print_I(user_input - 5);
        }
        else if (user_input == 9){
            cout << "IX";
        }
        else{
            cout << "X";
        }

        // add a new line
        cout << endl;
    }
    // print the error message for out of range numbers
    else{
        cout << "Given number is out of range" << endl;
    }
    return 0;
}
