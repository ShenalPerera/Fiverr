#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int main(){
    string filename;
    vector<string> words;

    cout << "Enter the filename : ";
    cin >> filename;

    ifstream fin(filename);

    // check error in the file open function
    if (fin.fail()) cerr << "File can not be opened\n";

    string tempWord;
    while (fin >> tempWord){
        // add word into the vector
        words.push_back(tempWord);
    }

    // print the count
    cout << words.size()<<" words were read from the file\n";

    cout << "Words list\n";
    cout << "==========\n\n";

    for (int i = 0; i < words.size(); ++i) {
        cout << words.at(i) << endl;
    }

    int letter_count;
    bool isFound = false;
    // Ask user to enter a positive number. Then display the all the words that contains that much of characters
    cout << "\n\nEnter the number of letters : " ;
    cin >> letter_count;

    for (int i = 0; i < words.size(); ++i) {
        if (words.at(i).size() == letter_count){
            cout << words.at(i) << endl;
            isFound = true;
        }
    }

    if (!isFound){
        cout << "No word found !" << endl;
    }


    // Guess the word
    string guess_word;
    cout << "Guss a word : ";
    cin >> guess_word;
    isFound = false;

    for (int i = 0; i < words.size(); ++i) {
        if (guess_word == words[i]){
            cout << "Guessed word is in the vector" << endl;
            isFound = true;
            break;
        }
    }
    if (!isFound){
        cout << "Guessed word is not in the vector"<< endl;
    }

    return EXIT_SUCCESS;
}