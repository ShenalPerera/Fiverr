#include <iostream>
#include <string>

#include "all_5_letters.h"
using namespace std;

int main(){

    string true_words[5] = {"FIVEY","SIXXY","seven","EigHt","Tenth"};
    string false_words[3] = {"Tenth","Th345","Six46gh"};
    if (all_5_letters(true_words,5)){
        cout << "Test 1 passed" << endl;
    }
    if (!all_5_letters(false_words,3)){
        cout << "Test 2 passed" << endl;
    }



    return EXIT_SUCCESS;
}
