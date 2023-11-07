#include <iostream>
#include "show_multiples.h"

using namespace std;
int main(){

    if (show_multiples(4) == 312) {
        cout << "Sum is correct" << endl;
    }
    else{
        cout << "Sum is wrong!" << endl;
    }

    if (show_multiples(6) == 468) {
        cout << "Sum is correct" << endl;
    }
    else{
        cout << "Sum is wrong!" << endl;
    }

    return EXIT_SUCCESS;
}