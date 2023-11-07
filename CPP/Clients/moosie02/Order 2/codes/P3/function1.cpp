#include "function1.h"
#include <vector>
#include <iostream>

using namespace std;

void function1(){
    vector<int> fib_numbers;
    fib_numbers.push_back(0);
    fib_numbers.push_back(1);

    int input;
    cout << "Enter the number of values : " << endl;
    cin >> input;

    for (int i = 0; i < input; ++i) {
        if (i == 0 || i == 1) cout << fib_numbers.at(i) << "\t";
        else{
            int temp = fib_numbers.at(i-1) + fib_numbers.at(i-2);
            fib_numbers.push_back(temp);
            cout << temp << "\t";
        }
    }
}
