#include <iostream>
#include "get_winner.h"

using namespace std;

int main(){

    cout << " Test 1 : get_winner('e','r') == " << get_winner('e','r') << endl;
    cout << " Test 2 : get_winner('r','r') == " << get_winner('r','r') << endl;
    cout << " Test 3 : get_winner('r','s') == " << get_winner('r','s') << endl;
    cout << " Test 4 : get_winner('s','p') == " << get_winner('s','p') << endl;
    cout << " Test 5 : get_winner('p','r') == " << get_winner('p','r') << endl;

    cout << " Test 6 : get_winner('s','r') == " << get_winner('s','r') << endl;
    cout << " Test 7 : get_winner('p','s') == " << get_winner('p','s') << endl;
    cout << " Test 8 : get_winner('r','p') == " << get_winner('r','p') << endl;
    return EXIT_SUCCESS;
}