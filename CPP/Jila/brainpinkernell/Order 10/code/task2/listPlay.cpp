#include <iostream>

using namespace std;

#include "Node.h"

int main(){
    Node * headPtr = nullptr;
    Node * newNode;
    int userInput;

    cout << "Enter a number : ";
    cin >> userInput;

    while (userInput != -1){
        newNode = new Node(userInput);

        if (headPtr == nullptr){
            headPtr = newNode;
        }
        else{
            newNode->setLink(headPtr);
            headPtr = newNode;
        }


        cout << "Enter a number : ";
        cin >> userInput;

    }

    cout << "Walking through the linked list:" << endl;
    cout << "----------------------------------" << endl;

    Node *nextPtr;
    nextPtr = headPtr;

    while (nextPtr != NULL) {
        cout << "nextPtr is pointing to node with value: "
             << nextPtr->getData() << endl;
        nextPtr = nextPtr->getLink();
    }

    // delete the nodes
    nextPtr = headPtr;

    while (headPtr != NULL){
        nextPtr = headPtr;
        headPtr = headPtr->getLink();
        free(nextPtr);
    }
    return 0;
}