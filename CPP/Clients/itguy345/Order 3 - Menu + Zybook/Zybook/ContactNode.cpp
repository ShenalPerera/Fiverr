#include "ContactNode.h"
#include <cstring>
#include <iostream>

using namespace std;

ContactNode::ContactNode(char* name, char* phoneNumber) {
    strcpy(this->contactName,name);
    strcpy(this->contactPhoneNum,phoneNumber);
    this->nextNodePtr = nullptr;
}

string ContactNode::GetName() {
    return this->contactName;
}

char *ContactNode::GetPhoneNumber() {
    return this->contactPhoneNum;
}

ContactNode* ContactNode::GetNext() {
    return this->nextNodePtr;
}

void ContactNode::InsertAfter(ContactNode *contactNode) {
    ContactNode* temp = nullptr;

    temp = this->nextNodePtr;
    this->nextNodePtr = contactNode;
    contactNode->nextNodePtr = temp;
}

void ContactNode::PrintContactNode() {
    cout <<"Name: " << contactName << endl;
    cout <<"Phone number: " << contactPhoneNum << endl;
}

