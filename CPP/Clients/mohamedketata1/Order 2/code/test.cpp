#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    vector<int> parity_list;
    parity_list.push_back(1);
    parity_list.push_back(2);
    parity_list.push_back(3);

    int error = 0;
    int size = parity_list.size();

    for (int i = 0; i < size; ++i) {
        error += ((int)parity_list.at(size-1 - i)) * pow(2,i);
    }

    cout << error;
    return 0;
}