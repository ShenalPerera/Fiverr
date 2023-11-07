#include <iostream>
#include <string>

#include "read_words.h"
#include "get_size.h"

using namespace std;

int main(){

    string filename = "test4.txt";

    // get the size of the words using get size function to declare the array
    int pre_size = get_size(filename);
    string words[pre_size];

    read_words(filename,words,pre_size);

    // print the array to check read is successful
    for (int i = 0; i < pre_size; ++i) {
        cout << words[i] << endl;
    }

    return EXIT_SUCCESS;
}