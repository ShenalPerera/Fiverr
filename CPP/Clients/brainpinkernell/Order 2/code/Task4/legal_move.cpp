#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "legal_move.h"

using namespace std;

bool legal_move(char a_char){
    return a_char == 'r' || a_char == 'p' || a_char == 's';
}