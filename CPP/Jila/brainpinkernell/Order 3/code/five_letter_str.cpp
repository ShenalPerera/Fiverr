#include "five_letter_str.h"
#include <string>

bool five_letter_str(string word){
    if (word.length() == 5){
        return true;
    }
    return false;
}