#include <iostream>

using namespace std;

int main(){
    int max;        // hold the current max value
    int input;      // hold the input

    // get the number 1 and assign it as the max
    cout << "Enter the number 1 : ";
    cin >> input;
    max = input;

    // get numbers from 2 to 15
    for (int i = 2; i <= 15; ++i) {
        cout << "Enter the number "<< i << " : ";
        cin >> input;

        // if max is less than input update the max
        if (input > max){
            max = input;
        }
    }

    // output the maximum number
    cout << "Maximum number is : " << max;

    return 0;
}