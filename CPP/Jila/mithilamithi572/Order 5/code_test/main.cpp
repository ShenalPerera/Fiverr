#include <iostream>

using namespace std;

#include "LinkedList.hpp"
int main() {
    LinkedList<int> test;
    test.insert(1,0);
    test.insert(2,0);
    test.insert(3,0);

    for (int i = 0; i < test.getSize(); ++i) {
        cout <<test.getAtPos(i)->getItem() <<" ";
    }
    int counter = 0;
    test.bubbleSort(std::less<int>,&counter)
    return 0;
}
