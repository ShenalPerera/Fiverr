#include <iostream>

using namespace std;

// This program get number from the user and calculate the absolute  average of the given numbers. User should enter 0 to give lat input
int main(){
    int input;
    int count = 0;
    int sum = 0;
    int abs_max = -1;
    do {
        cout << "Enter a number (0 to terminate): ";
        cin >> input;

        if (input < 0){
            input =-1 * input; // get the absolute
        }

        sum += input;
        cout << "Current absolute sum is " << sum << endl;

        if (input > abs_max){
            abs_max = input;
        }

        count++;
    } while (input != 0);

    cout << "Absolute average of given numbers is : " << sum/(double )(count-1) << endl;
    cout << "Absolute maximum value is : " << abs_max << endl;
    return 0;
}