#include <iostream>
#include "get_fibonacci_value.hpp"

using namespace std;

int main(){

    for (int i = 10; i <= 50 ; i=i+10) {
        cout << "F(" << i << ") = " << get_fibonacci_value(i) << endl;

    }



    return 0;
}