#include <iostream>
#include "Clock12.h"
using namespace std;

int main(){
    Clock12 clock12(10,11,00);
    clock12.display();
    clock12.addHours();
    clock12.display();

    clock12.addHours();
    clock12.display();

    clock12.addHours();
    clock12.display();
    return 0;
}
