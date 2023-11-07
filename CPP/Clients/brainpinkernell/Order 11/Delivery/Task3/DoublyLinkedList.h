//--------------------------------------------------
//  class: DoublyLinkedList
//
//  purpose: To implement a Double Linked List object
//
//  member functions: has 3 member functions:
//           *   doublyLinkedList creates a DLL object
//           *   addToDLLTail adds a node to the DLL at the tail
//	   *   deleteFromDLLTail deletes a node from the DLL at the tail
//
//  
//  last modified: 2014-09-18
//
//--------------------------------------------------

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

//--------------------------------------------------
//  class: DLLNode
//
//  purpose: To create a data element for a Doubly Linked List
//
//  By: David Tuttle
//  Last modified: 08 Feb 2023
//
//--------------------------------------------------
class DLLNode {
public:
    DLLNode();
    DLLNode(const double el, DLLNode *n = NULL, DLLNode *p = NULL) {
        info = el;      // Place value into new node
        next = n;       // Set link to next node in list
        prev = p;       // Set link to previous node in list
    };

    double info;
    DLLNode *next, *prev;
};

class DoublyLinkedList {
public:
    DoublyLinkedList();           // Class constructor
    void addToDLLTail(double el); // Add a DLLNode with value el to tail of DLL
    double deleteFromDLLTail();   // Remove a DLLNode from tail of DLL
    double addToDLLHead(double el);
    double deleteFromDLLHead();
    DLLNode* getHead();
private:
    DLLNode *head, *tail;
};

#endif
