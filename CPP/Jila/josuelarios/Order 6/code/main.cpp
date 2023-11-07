#include <iostream>
using namespace std;


int menu();

// Function to generate random numbers between given range
int getRandInt(int minValue,int maxValue);

// Function to perform addition practice
int addition(int number1,int number2);

// Function to perform the multiplication
int multiplication(int number1, int number2);

// Function to perform the modulus
int modulusCalc(int number1, int number2);

int randomOperation(int number1, int number2);


int main() {
    srand(time(nullptr));

    int user_choice  = menu();

    do {


        int operand1 = getRandInt(0,99);
        int operand2 = getRandInt(0,99);

        int result;

        if (user_choice == 1) result = addition(operand1,operand2);
        else if (user_choice == 2) result = multiplication(operand1,operand2);
        else if (user_choice == 3) result = modulusCalc(operand1,operand2);
        else if (user_choice == 4) result = randomOperation(operand1,operand2);
        else if (user_choice == 5) break;
        else{
            cout << "Invalid input!" << endl;
            user_choice = menu();
            continue;
        }

        int answer;
        cin >> answer;

        if (answer == -1) user_choice = menu();

        else if(answer == result){
            cout << "Answer is correct!" << endl;
        }

        else cout << "Answer is wrong!" << endl;

        cout << endl;
    } while (true);

    cout << "Good bye" << endl;

    return 0;
}


//=========================== Functions =====================================
// menu function to show the menu and get the input
int menu(){
    // hold the user input
    int user_input;

    cout << "SELECT YOUR OPTION" << endl;
    cout << "1) ADDITIONS." << endl;
    cout << "2) MULTIPLICATIONS." << endl;
    cout << "3) MODULUS." << endl;
    cout << "4) RANDOM OPERATIONS." << endl;
    cout << "5) EXIT." << endl;
    cout << ">>";

    // get the user input
    cin >> user_input;

    return user_input;
}

// Function to generate random numbers between given range
int getRandInt(int minValue,int maxValue){
    return (rand() % (maxValue - minValue + 1)) + minValue;
}

// Function to perform addition practice
int addition(int number1, int number2){

    // show the question to the user
    cout << number1 << " + " << number2 << " = __";

    // return the expected results
    return (number1 + number2);
}


// Function to perform the multiplication
int multiplication(int number1, int number2){

    // show the question to the user
    cout << number1 << " * " << number2 << " = __";

    return number2 * number1;
}


int modulusCalc(int number1, int number2){
    // show the question to the user
    cout << number1 << " % " << number2 << " = __";
    return number1 % number2;
}

int randomOperation(int number1, int number2){
    int number = getRandInt(1,3);

    if (number == 1) return addition(number1,number2);
    else if (number == 2) return multiplication(number1,number2);
    else return modulusCalc(number1,number2);
}
