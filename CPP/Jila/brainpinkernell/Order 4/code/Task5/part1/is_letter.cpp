#include "is_letter.h"

bool is_letter(char a_char){
    if((a_char >= 'a' && a_char <= 'z') || (a_char >= 'A' && a_char <= 'Z')) {
        return true;
    }
    else{
        return false;
    }
}
