#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "letter_match.h"
#include "letter_elsewhere.h"

string guess_match(string word_of_day, string word_guess){
    string match_result = "";
    int guess_len = word_guess.length();

    for (int i = 0; i < guess_len ; ++i) {
        if (letter_match(word_of_day,word_guess,i)){
            match_result += "green ";
        }
        else if(letter_elsewhere(word_of_day,word_guess,i)){
            match_result += "gold ";
        }
        else{
            match_result += "gray ";
        }
    }
    return match_result;
}
