#include <iostream>

using namespace std;

int main() {
    int  integers[10];

    int minIndex = 0;

    for (int i = 0; i < 10; ++i) {
        cout << "Please input the value at index " << i << " in the array: ";
        cin >> integers[i];


        if (integers[i] < integers[minIndex]){
            minIndex = i ;
        }

    }

    cout << "\nThe lowest value is " << integers[minIndex] << " index " << minIndex;
    return 0;
}
