#include "getSumOfDigits.hpp"

int getSumOfDigits(int n){
    // hold the sum
    int sum = 0;

    // Get each digit by deviding and take the remainder until n >0
    while (n > 0) {
        int digit = n % 10;
        n = n / 10;
        sum += digit * digit;
    }
    return sum;

}

