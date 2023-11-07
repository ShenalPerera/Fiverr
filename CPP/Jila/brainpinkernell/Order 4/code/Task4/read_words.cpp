#include <iostream>
#include <string>
#include <fstream>

#include "read_words.h"

void read_words(string filename, string words[],int size){
    ifstream readfile(filename);        // open the stream
    int read_size;                      // hold the read size from the file

    readfile >> read_size;              // read the size

    if (read_size == size){             // compare the two sizes
        for (int i = 0; i < size; ++i) {
            readfile >> words[i];       // read each words into the array
        }
    }

    else{
        cout << "Words size and given size are not match" << endl;
    }

}
