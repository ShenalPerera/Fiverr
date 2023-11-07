#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "letter_match.h"

using namespace std;

bool letter_elsewhere(string word_of_day, string word_guess, int pos){
    if (letter_match(word_of_day,word_guess,pos)){
        return false;
    }
    else{
        char match_letter = word_guess.at(pos);
        bool found_yet = false;
        int word_len = word_of_day.length();
        int next_pos = 0;

        while (!found_yet && (next_pos < word_len)){

            if (next_pos != pos){
                if (word_of_day.at(next_pos) == match_letter){
                    found_yet = true;
                }
            }
            next_pos = next_pos + 1;
        }

        return found_yet;
    }
}