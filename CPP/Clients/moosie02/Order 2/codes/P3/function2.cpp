#include <iostream>
#include <vector>

#include "function2.h"

using namespace std;

void function2(){
    vector<int> fib_numbers;
    fib_numbers.push_back(0);
    fib_numbers.push_back(1);

    int  input;
    cout << "Enter the number of values : ";
    cin >> input;

    for (int i = 2; i < input * (input + 1) / 2; ++i) {
        fib_numbers.push_back(fib_numbers.at(i-1) + fib_numbers.at(i-2));
    }

    int next_value = 0;

    for (int i = 0; i < input; ++i) {

        for (int j = 0; j <=i ; ++j) {
            cout << fib_numbers.at(next_value++) << "\t";
        }
        cout << endl;
    }
}