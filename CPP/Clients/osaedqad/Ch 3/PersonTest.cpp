// PersonTest.cpp
// Test application for the Person class

#include <iostream>
using namespace std;

#include "Person.h"

int main()
{
    Person person( "John", "Smith", 19 );

    cout << "Created " << person.getFirstName() << " " << person.getLastName() << ", age "
    << person.getAge() << endl;
    person.setAge (person.getAge() + 1);
    cout << "Happy Birthday to " << person.getFirstName() << " "
    << person.getLastName() << endl;
} // end main