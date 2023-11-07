#include <iostream>
#include <fstream>
#include "reverse.h"
#include "is_palindrome.h"

using namespace std;

int main(){
    ofstream fout("newfile.txt");
    ifstream fin("input.txt");
    if (fout.fail() || fin.fail()){
        cerr << "File cannot be open" << endl;
        exit(1);
    }

    string word;

    while (!fin.eof()){
        fin >> word;
        if (is_palindrome(word)){
            fout << word << endl;
        }
        else{
            cout << word << endl;
        }
    }
    return 0;
}