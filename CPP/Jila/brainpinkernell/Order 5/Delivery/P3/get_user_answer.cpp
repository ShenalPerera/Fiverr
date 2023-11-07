#include <iostream>
#include "get_user_answer.h"

using namespace std;

void get_user_answer(char * ch_pointer){
    char user_input;
    do {
        cout << "Enter the character (a,b,c or d) : ";
        cin >> user_input;
        if (user_input == 'a' || user_input == 'b' || user_input == 'c' || user_input == 'd'){
            *ch_pointer = user_input;
            break;
        }
    } while (true);
}
