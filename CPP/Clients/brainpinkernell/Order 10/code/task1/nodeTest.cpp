// CS 211 Fall 2022 - Programming Assignment #1
// Written by: Sharon Tuttle
// Modified by: David C. Tuttle
// Modified by: <YOUR NAME HERE>
//
// Last modified: 25 Jan 2023

/*-------
  Signature: main: void -> int

  Purpose: testing program for the class Node

  Examples: when run, the following should be printed
      to the screen:

testing class Node - true means test passed:
--------------------------------------------
testing constructors and getters:
true true true true true true true true

testing setters:
true true true

walking through little 4-node proto-list:
-----------------------------------------
next is pointing to node w/data: 100
next is pointing to node w/data: 200
next is pointing to node w/data: 300
next is pointing to node w/data: 400

--------*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Node.h"

using namespace std;

int main() {
    cout << boolalpha << endl;

    // Calling all 4 Node constructors
    // Note that the list is NOT fully built here!

    Node newNode4;
    Node newNode3(&newNode4);
    Node newNode2(200);
    Node newNode1(100, &newNode2);

    Node newNode5(500,NULL);
    newNode4.setLink(&newNode5);
    cout << "Testing class Node - true means test passed:" << endl;
    cout << "--------------------------------------------" << endl;

    // Testing constructors and accessors

    cout << "*** Testing constructors and accessors:" << endl;

    cout << (newNode4.getData() == 0) << " ";
    cout << (newNode3.getData() == 0) << " ";
    cout << (newNode2.getData() == 200) << " ";
    cout << (newNode1.getData() == 100) <<  " ";

    cout << (newNode4.getLink() == NULL) << " ";
    cout << (newNode3.getLink() == &newNode4) << " ";
    cout << (newNode2.getLink() == NULL) << " ";
    cout << (newNode1.getLink() == &newNode2) << " ";
    cout << endl << endl;

    // Testing setters - HERE is where we finish
    // constructing the linked list!


    cout << "*** Testing setters:" << endl;

    newNode4.setData(400);
    cout << (newNode4.getData() == 400) << " ";

    newNode3.setData(300);
    cout << (newNode3.getData() == 300) << " ";

    newNode2.setLink(&newNode3);
    cout << (newNode2.getLink() == &newNode3) << " ";
    cout << endl << endl;

    // Now we should have a fully constructed linked list:
    // 100 --> 200 --> 300 --> 400 --> NULL

    // Let's "walk" through the list

    cout << "Walking through the linked list:" << endl;
    cout << "----------------------------------" << endl;

    Node *nextPtr;
    nextPtr = &newNode1;

    while (nextPtr != NULL) {
        cout << "nextPtr is pointing to node with value: "
             << nextPtr->getData() << endl;
        nextPtr = nextPtr->getLink();
    }

    cout << endl;
    return EXIT_SUCCESS;
}
