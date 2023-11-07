/*-----
   Implements the methods for the Node class

   written by: Sharon Tuttle
   modified by: David C. Tuttle
   last modified: 25 Jan 2023
-----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Node.h"

using namespace std;

// constructors

/*-----
    no-argument constructor: expects nothing, and creates
        a new Node instance whose data field is the default
	for the valueType, and whose link field is NULL
-----*/

Node::Node() {
    dataField = valueType();
    linkPtr = NULL;
}

/*----- 
    first one-argument constructor: expects a pointer to a Node, and
        creates a new Node instance whose data field is the default
        for the valueType, and whose link field is set to the given
        pointer
-----*/

Node::Node(Node *initLink) {
    dataField = valueType();
    linkPtr = initLink;
}

/*----- 
    second one-argument constructor: expects a valueType value, and
        creates a new Node instance whose data field is the given
        value, and whose link field is set to NULL
-----*/

Node::Node(const valueType& initData) {
    dataField = initData;
    linkPtr = NULL;
}

/*-----
    two-argument constructor: expects a valueType value and a pointer
        to a Node, and creates a new Node instance whose data field is
        the given valueType value and whose link field is set to the
        given pointer
-----*/

Node::Node(const valueType& initData, Node *initLink) {
    dataField = initData;
    linkPtr = initLink;
}
 
// accessors - methods to access data fields

/*-----
    signature: getData: void -> valueType
    purpose: expects nothing, and returns the value of the
        calling Node's data field
-----*/

valueType Node::getData() const {
    return dataField;
}

/*-----
    signature: getLink: void -> *Node
    purpose: expects nothing, and returns the value of the
        calling Node's link field

    TWO VERSIONS provided -- one returns a const version of
    the *Node, and one does not -- compiler allegedly uses
    the "correct" one for a given call.
-----*/

Node* Node::getLink() const {
    return linkPtr;
}

Node* Node::getLink() {
    return linkPtr;
}

// setters - methods to set data fields

/*-----
    signature: setData: valueType -> void
    purpose: expects data to be stored in a Node, and returns nothing,
        but has the side-effect of setting the calling Node's
	data field to the given value
-----*/

void Node::setData(const valueType& newData) {
    dataField = newData;
}

/*-----
    signature: setLink: *Node -> void
    purpose: expects a pointer to a Node, and returns nothing,
        but has the side-effect of setting the calling Node's
	link field to the given Node pointer
-----*/
        
void Node::setLink(Node *newLinkPtr) {
    linkPtr = newLinkPtr;
}

