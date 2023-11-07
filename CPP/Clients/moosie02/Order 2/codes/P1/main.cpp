#include <iostream>

#include "goldbach_expectation.h"

using namespace std;

int main(){
    int input_number;
    cout << "Enter an even number between 4 and 50000 : ";
    cin >> input_number;

    goldbach_expectation(input_number);

}