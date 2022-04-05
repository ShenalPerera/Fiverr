#include <iostream>
#include "ContactNode.h"

int main() {
    char name[30] ;
    char phoneNumber[15] ;

    cout << "Person 1\nEnter name:" << endl;
    cin.getline(name,30);
    cout << "Enter phone number:" << endl;
    cin.getline(phoneNumber,15);

    ContactNode *person1 = new ContactNode(name,phoneNumber);
    cout << "You entered: " << name <<", " << phoneNumber << endl << endl;


    cout << "Person 2\nEnter name:" << endl;
    cin.getline(name,30);
    cout << "Enter phone number:" << endl;
    cin.getline(phoneNumber,15);

    ContactNode *person2 = new ContactNode(name,phoneNumber);
    cout << "You entered: " << name <<", " << phoneNumber << endl << endl;

    cout << "Person 3\nEnter name:" << endl;
    cin.getline(name,30);
    cout << "Enter phone number:" << endl;
    cin.getline(phoneNumber,15);

    ContactNode *person3 = new ContactNode(name,phoneNumber);
    cout << "You entered: " << name <<", " << phoneNumber << endl << endl;

    ContactNode *headPtr ;


    headPtr = person1;
    headPtr->InsertAfter(person2);
    person2->InsertAfter(person3);


    ContactNode * currentNode = headPtr;
    cout << "CONTACT LIST" << endl;
    while (currentNode != nullptr){
        currentNode->PrintContactNode();
        currentNode = currentNode->GetNext();
    }

    return 0;
}
