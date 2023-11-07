// Person.cpp
// Creates and manipulates a person with a first name, last name and age
#include <string>
#include "Person.h"

Person::Person(string first, string last, int years) {
    firstName = first;
    lastName = last;
    if ( years > 0 )
        age = years;
} // end Person constructor

string Person::getFirstName( )
{
    return firstName;
} // end function getFirstName

void Person::setFirstName( string first )
{
    firstName = first;
} // end function setFirstName

string Person::getLastName()
{
    return lastName;
} // end function getLastName

void Person::setLastName( string last )
{
    lastName = last;
} // end function setLastName

int Person::getAge()
{
    return age;
} // end function getAge

void Person::setAge( int years )
{
    if ( years > 0 )
        age = years;
} // end function setAge
