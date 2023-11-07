#include <iostream>
#include <string>

#include "five_letter_str.h"

int main(){
    string test1 = "moo";
    string test2 = "five5";

    if (!five_letter_str(test1)){
        cout << "Test 1 : passed (moo = 3)" << endl;

    }
    if (five_letter_str(test2)){
        cout << "Test 2 : passed (five5 = 5)" << endl;
    }
    return EXIT_SUCCESS;
}