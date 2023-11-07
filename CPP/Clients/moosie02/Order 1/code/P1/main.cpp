// Include the built-in libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    // create an object of the fstream with given file name
    ifstream fin("input.dat");

    // Check the status of the file
    if (fin.fail()){

        cerr << "Error opening input file!" << endl;
        exit(1);
    }

    // Define the output stream with the file name
    ofstream fout("output.dat");

    // check the status of the file
    if (fout.fail()){

        cerr << "Error opening output file!" << endl;
        exit(1);
    }

    // Read the file content to the string called content
    string content;

    fin >> content;

    // write the content to the output file
    fout << content;

    // close the file
    fin.close();
    fout.close();

    return 0;
}