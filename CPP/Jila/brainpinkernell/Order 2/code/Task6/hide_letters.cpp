#include <iostream>
#include "hide_letters.h"
#include "is_letter.h"

#include <string>

using namespace std;

string hide_letters(string phrase){
    string hide_phrase = "";
    for (char i : phrase) {
        if (is_letter(i)){
            hide_phrase += "_";
        }
        else{
            hide_phrase += i;
        }
    }
    return hide_phrase;
}
