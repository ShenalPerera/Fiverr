#include <iostream>
#include "isHappy.hpp"
#include <string>

using namespace std;

string boolToYN(bool );

int main(){
    cout << "Is 19 Happy? " << boolToYN(isHappy(19)) << endl;
    cout << "Is  2 Happy? " << boolToYN(isHappy(2)) << endl;
    return 0;
}


string boolToYN(bool is_happy){
    return isHappy(is_happy) ? "Yes" : "No";
}