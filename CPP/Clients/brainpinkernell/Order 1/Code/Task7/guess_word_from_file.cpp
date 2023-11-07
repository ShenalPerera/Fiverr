#include <iostream>
#include <string>
#include <fstream>

#include "get_size.h"
#include "rand_int.h"
#include "add_to_file.h"
#include "guess_match.h"

using namespace std;

int main(){

    string filename;
    int word_size;

    // prompt user for the filename
    cout << "Please enter the file : ";

    // get the user input
    cin >> filename;

    word_size = get_size(filename); // read the first line and get word count;

    string words[word_size];                // declare an array

    string temp_word;
    ifstream read_file(filename);           // open a stream for the reading

    read_file >> word_size;                 // ignore the first line

    for (int i = 0; i < word_size; ++i) {   // read the file words into tem variable
        read_file >> words[i];              // save the words into the array
    }

    read_file.close();                      // Close the stream

    int random_number = rand_int(0,word_size-1);

    string word_of_day = words[random_number];  // get the word of the day

    add_to_file("words_used.txt",word_of_day);  // add the file

    string guess_word;
    char enter;


    bool isMatch = false;
    bool trigger = true;
    bool isQuite = false;
    while (!isQuite){

        cout << "Enter the guess word : ";
        if (trigger){
            cin.ignore();
            trigger = false;
        }
        enter = cin.peek();
        if (enter == '\n') {
            isQuite = true;
        }

        if (!isQuite){
            getline(cin,guess_word);
            if (guess_word == word_of_day){
                isMatch = true;
                isQuite = true;
            }
            if (guess_word != word_of_day || guess_word.length() == 0){
                cout << guess_match(word_of_day,guess_word) << endl;
            }
        }






    }
    if (isMatch) cout << "Congratulations! You guessed the word of the day" << endl;
    else   cout << "Good bye ! " << endl;




    return EXIT_SUCCESS;
}