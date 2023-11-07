#include "get_fibonacci_value.hpp"

long int get_fibonacci_value(int n){
    // return 0 if n is zero
    if (n == 0) return 0;

    //return 1 if n is one
    else if (n == 1) return 1;

    else{
        return get_fibonacci_value(n-1) + get_fibonacci_value(n-2);
    }
}