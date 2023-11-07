// Person.h
// Creates and manipulates a person with a first name, last name and age

#include <string>
using namespace std;

class Person
{
public:
    Person( string, string, int );
    string getFirstName( );
    void setFirstName( string );
    string getLastName();
    void setLastName( string );
    int getAge();
    void setAge( int );
private:
    string firstName;
    string lastName;
    int age;
}; // end class Person