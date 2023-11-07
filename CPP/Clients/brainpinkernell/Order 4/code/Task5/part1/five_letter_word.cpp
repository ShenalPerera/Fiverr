/*----
  signature:five_letter_word: string -> bool
  purpose: expects a five letter word and determines if it contain all
            letters and if the word is exactly 5 characters
  tests: (five_letter_word("apple") == true)
         (five_letter_word("y3llew") == false)

  by: 
  last modified: 2022-09-02
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "is_letter.h"
using namespace std;

bool five_letter_word(string word_input)
{
    char letter_check;
    bool proper_word = false;
    if(word_input.length()== 5)
    {
        for (int i = 0; i < 5; i++)
        {
            letter_check = word_input.at(i);
            is_letter(letter_check);
            if (is_letter(letter_check) )
            {
                proper_word = true;
            
            }
            else return false;
        }
    }
    return proper_word;

}