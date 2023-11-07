#include <iostream>

using namespace std;

unsigned int gcd(unsigned int m, unsigned int n){
    if (n == 0) {
        return m;
    }
    return gcd(n, m % n);
}


//int main() {
//    int a = 36, b = 24;
//    std::cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b);
//    return 0;
//}