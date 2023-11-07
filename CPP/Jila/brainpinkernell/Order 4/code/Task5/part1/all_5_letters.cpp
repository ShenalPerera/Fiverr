#include "all_5_letters.h"
#include "five_letter_word.h"

bool all_5_letters(const string words[], int size){

    for (int i = 0; i < size; ++i) {
        if (!five_letter_word(words[i])){
            return false;
        }
    }
    return true;
}