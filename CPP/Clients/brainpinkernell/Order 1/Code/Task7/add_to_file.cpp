#include <fstream>
#include "add_to_file.h"
#include <string>

using namespace std;

int add_to_file(string filename, string word){
    int length ;
    for (length = 0;  word[length] != '\0'; ++length) {}    // count the length of the word

    ofstream log_file_stream(filename,ios::app);            // open file for appending

    log_file_stream << word << endl;

    log_file_stream.close();                                // close the file stream
    return length;
}