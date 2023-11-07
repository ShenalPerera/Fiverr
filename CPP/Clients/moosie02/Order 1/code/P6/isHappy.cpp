#include "isHappy.hpp"
#include <iostream>
#include "getSumOfDigits.hpp"

using namespace std;
bool isHappy(int n){
    int slowIteration = n;
    int fastIteration = getSumOfDigits(n);

    // check whether there is a point if these slow and fast are meet
    while (fastIteration != 1 && slowIteration != fastIteration){
        // if not update the next hop of the iterations
        slowIteration = getSumOfDigits(slowIteration);
        fastIteration = getSumOfDigits(getSumOfDigits(fastIteration));
    }

    return fastIteration == 1;
}
