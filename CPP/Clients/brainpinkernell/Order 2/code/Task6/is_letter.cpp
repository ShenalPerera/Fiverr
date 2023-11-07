#include "is_letter.h"

bool is_letter(char letter){
    return ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'));
}
