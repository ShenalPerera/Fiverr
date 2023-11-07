#include <iostream>
using namespace std;

void addCommas(unsigned long long int number){
    if (number < 1000) {
        cout << number;
        return;
    }
    addCommas(number / 1000);
    cout << "," << to_string(number % 1000 + 1000).substr(1);

}

//int main(){
//    addCommas(9008007006);
//    return 0;
//}