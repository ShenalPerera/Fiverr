#include <iostream>
#include <vector>
#include <algorithm>

#include "goldbach_expectation.h"
#include "binary_search.h"

using namespace std;

void goldbach_expectation(int n){
    int prime_numbers[5136];

    prime_numbers[1] = 2;
    prime_numbers[2] = 3;

    int current_pointer=3;

    for(int num=5; num<=50000; num++){
        bool f = false;
        for(int i=1; i < current_pointer; i++){
            if(prime_numbers[i] * prime_numbers[i] > num){
                break;
            }
            if(num % prime_numbers[i] == 0) {
                f = true;
                break;
            }
        }
        if(!f) {
            prime_numbers[current_pointer++] = num;
        }
    }
    prime_numbers[current_pointer] = 50001;

    if(!n || n %2 != 0 || n > 50000){
        cout << "Invalid input" << endl;
        return;
    }
    int count = 0;
    if(n%2==0){

        for(int i=1; prime_numbers[i] <= n / 2; i++){
            if(binary_search(prime_numbers, current_pointer, n - prime_numbers[i]) != -1) {
                cout << prime_numbers[i] << " + " << n - prime_numbers[i] << " = " << n << endl;
                count++;
            }
        }
    }
}
