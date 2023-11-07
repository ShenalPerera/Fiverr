#include <iostream>
#include "add_to_file.h"

using namespace std;

int main(){
    int length_of_word1 = add_to_file("test_3.txt","test1");
    int length_of_word2 = add_to_file("test_4.txt","Longword");

    cout << "Append to the file 1. Length of the word is " << length_of_word1 << endl;
    cout << "Append to the file 2. Length of the word is " << length_of_word2 << endl;

    return EXIT_SUCCESS;
}
