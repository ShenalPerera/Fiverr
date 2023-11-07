#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(){
    DoublyLinkedList list;

    list.addToDLLHead(10.0);
    list.addToDLLHead(21.0);
    list.addToDLLHead(32.0);

    // Expected output: 32.0 21.0 10.0
    for (DLLNode* p = list.getHead(); p != NULL; p = p->next)
        cout << p->info << " ";
    cout << endl;

    list.deleteFromDLLHead();
    list.deleteFromDLLHead();

    // Expected output: 10.0
    for (DLLNode* p = list.getHead(); p != NULL; p = p->next)
        cout << p->info << " ";
    cout << endl;

    return 0;
}
