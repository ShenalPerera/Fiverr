#include "function3.h"
#include <iostream>
#include <vector>

using namespace std;

void function3(){
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

    for (int i = input; i >0; --i) {
        for (int j = i; j > 0 ; --j) {
            cout << fib_numbers.at(next_value++) << "\t";
        }
        cout << endl;
    }
}