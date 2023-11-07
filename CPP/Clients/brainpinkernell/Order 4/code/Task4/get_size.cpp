#include <string>
#include <iostream>
#include <fstream>

#include "get_size.h"

int get_size(string filename){
    ifstream ReadFile(filename);    // Create object of ifstream with given argument filename

    int numberOfLine;

    ReadFile >> numberOfLine;       // store the number of line

    ReadFile.close();               // close the file

    return numberOfLine;            // return the first line integer

}
