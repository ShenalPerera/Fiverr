#include "reverse.h"

string reverse(string word){
    string copy_word = word.substr(0,word.size());

    int n = copy_word.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(copy_word[i], copy_word[n - i - 1]);

    return copy_word;
}