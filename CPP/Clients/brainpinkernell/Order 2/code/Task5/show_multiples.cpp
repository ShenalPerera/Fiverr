#include <iostream>
#include "show_multiples.h"

using namespace std;

int show_multiples(int number){
    int sum = 0;
    for (int i = 1; i < 13; ++i) {
        cout << i << " x " << number << " = " << number * i << endl;
        sum += number * i;
    }
    return sum;
}
