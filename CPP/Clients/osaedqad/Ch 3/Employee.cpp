// Lab 3: Employee.cpp
// Employee class member-function definitions.
#include <iostream>
using namespace std;

#include "Employee.h" // Employee class definition

/* Define the constructor. Assign each parameter value to the appropriate data
member. Write code that validates the value of salary to ensure that it is
not negative. */
Employee::Employee(string firstName, string lastName, int salary) {
    setFirstName(firstName);
    setLastName(lastName);
    setMonthlySalary(salary);

}
/* Define a set function for the first name data member. */
void Employee::setFirstName(string fname) {
    firstName = fname;
}

/* Define a get function for the first name data member. */
string Employee::getFirstName() {
    return firstName;
}

/* Define a set function for the last name data member. */
void Employee::setLastName(string lname) {
    lastName = lname;
}

/* Define a get function for the last name data member. */
string Employee::getLastName() {
    return lastName;
}

/* Define a set function for the monthly salary data member. Write code
that validates the salary to ensure that it is not negative. */
void Employee::setMonthlySalary(int salary) {
    if (salary >= 0){
        monthlySalary = salary;
    } else{
        monthlySalary = 0;
    }
}

/* Define a get function for the monthly salary data member. */
int Employee::getMonthlySalary(){
    return monthlySalary;
}