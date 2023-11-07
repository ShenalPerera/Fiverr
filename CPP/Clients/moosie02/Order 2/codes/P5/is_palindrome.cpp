#include "is_palindrome.h"
#include "reverse.h"

using namespace std;

bool is_palindrome(string word){
    return word == reverse(word);
}