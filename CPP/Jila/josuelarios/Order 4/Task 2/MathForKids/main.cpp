#include <iostream>

using namespace std;

// menu function to show the menu and get the input
int menu();

// Function to generate random numbers between given range
int getRandInt(int minValue,int maxValue);

// Function to perform addition practice
int addition();

// Function to perform the subtraction
int subtraction();

// Function to perform the multiplication
int multiplication();

// function to get
bool ynToBool(char character);

// display the play main menu
bool playAgain();

// print the results
bool printResults(int result);



int main() {
    srand(time(0));

    // keep the user input for the main menu
    int choice;

    // bool to identify the current round is play again round r a normal round
    bool isPlayAgain = false;   // initial round is not play again state

    // bool value check answer is correct
    bool isCorrect;

    // hold the current result
    int result;

    // Total number of questions and correct answers
    int total = 0;
    int correct = 0;

    do {
        // show the menu and get the input if the state is not a play again
        if (!isPlayAgain) choice = menu();


        if (choice == 1) result = addition();
        else if (choice == 2) result = multiplication();
        else if (choice == 3) result = subtraction();
        else if (choice == 4) break;
        else{
            cout << "Wrong input!" << endl;
            continue;
        }

        isCorrect = printResults(result);                   // Get the results

        cout << "\nTotal questions : " << ++total << endl;

        // increase the correct answers
        if (isCorrect) ++correct;

        cout << "Correct answers : " << correct << endl;
        cout << "Wrong answers   : " << total- correct  << endl;

        isPlayAgain = playAgain();

    } while (true);
    return 0;
}


//=========================== Functions =====================================
// menu function to show the menu and get the input
int menu(){
    // hold the user input
    int user_input;

    cout << "Please select an option:" << endl;
    cout << "\t1 - Practice with sum" << endl;
    cout << "\t2 - Practice with products" << endl;
    cout << "\t3 - Practice with subtractions" << endl;
    cout << "\t4 - Exit" << endl;
    cout << ">>";

    // get the user input
    cin >> user_input;

    return user_input;
}


// Function to generate random numbers between given range
int getRandInt(int minValue,int maxValue){
    return (rand() % (maxValue - minValue + 1)) + minValue;
}


// function to get
bool ynToBool(char character){
    if (towlower(character) == 'y') return true;
    else if (towlower(character) == 'n') return false;
}


// Function to perform addition practice
int addition(){
    int number1 = getRandInt(0,100); // get numbers 0,1,2,3,...,99,100
    int number2 = getRandInt(0,100);

    // show the question to the user
    cout << number1 << " + " << number2 << " = ";

    // return the expected results
    return (number1 + number2);

}

// Function to perform the subtraction
int subtraction(){
    int number1 = getRandInt(0,100); // get numbers 0,1,2,3,...,99,100
    int number2 = getRandInt(0,100);

    int temp;       // temp value to get help when swap

    // swap the numbers if number1 is greater than other
    if (number1 < number2){
        temp = number1;
        number1 = number2;
        number2 = temp;
    }

    // show the question to the user
    cout << number1 << " - " << number2 << " = ";

    // return the correct results
    return number1 - number2;

}

// Function to perform the multiplication
int multiplication(){
    int number1 = getRandInt(0,10);    // get numbers 0,1,2,3,...,99,100
    int number2 = getRandInt(0,100);

    // show the question to the user
    cout << number1 << " * " << number2 << " = ";

    return number2 * number1;
}


bool playAgain(){
    char c;
    cout << "play again (y/n) ";
    cin >> c;
    return ynToBool(c);
}

// print the results
bool printResults(int result){
    // get the answer from the user
    int user_input;
    cin >> user_input;  // get the input

    // print the results
    if (user_input == result) {
        cout << "Great" << endl; // print the great message if the number is correct
        return true;
    }
    else cout << "Correct answer is : " << result << endl;   // print he correct answer
    return false;
}