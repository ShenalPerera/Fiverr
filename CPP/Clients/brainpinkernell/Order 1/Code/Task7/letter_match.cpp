#include <iostream>
#include <string>


using namespace std;

bool letter_match(string word_of_day,string word_guess, int pos){
    return (pos < word_of_day.length()) &&
           (pos < word_guess.length()) &&
            (word_of_day.at(pos) == word_guess.at(pos));
}