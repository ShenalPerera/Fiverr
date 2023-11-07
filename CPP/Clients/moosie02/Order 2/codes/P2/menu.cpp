#include <iostream>

#include "menu.h"


using namespace std;

void menu(){


    do {

        int input;
        cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Exit\nEnter your choice : ";
        cin >> input;
        if (input == 5 ) break;

        srand(time(0));

        double answer;
        long int operand1 = rand() % 100000 - 50000;
        long int operand2 = rand() % 100000 - 50000;

        switch (input) {
            case 1:
                cout << operand1 << " + " << operand2 << " = " << endl;
                cin >> answer;
                if (answer == (double )(operand1+ operand2)){
                    cout << "your answer is correct!" << endl;
                }
                else{
                    cout << "Your answer is wrong!" << endl;
                }
                break;
            case 2:
                cout << operand1 << " - " << operand2 << " = " << endl;
                cin >> answer;
                if (answer == (double )(operand1 - operand2)){
                    cout << "your answer is correct!" << endl;
                }
                else{
                    cout << "Your answer is wrong!" << endl;
                }
                break;
            case 3:
                cout << operand1 << " * " << operand2 << " = " << endl;
                cin >> answer;
                if (answer == (double )(operand1 * operand2)){
                    cout << "your answer is correct!" << endl;
                }
                else{
                    cout << "Your answer is wrong!" << endl;
                }
                break;
            case 4:
                cout << operand1 << " / " << operand2 << " = " << endl;
                cin >> answer;
                if (answer == (( long double )operand1 / operand2)){
                    cout << "your answer is correct!" << endl;
                }
                else{
                    cout << "Your answer is wrong!" << endl;
                }
                break;
        }
    } while (true);
}




