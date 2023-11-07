#include <iostream>
#include "Account.h"

// constructors
Account::Account()= default;

Account::Account(const string firstNameIn, const string lastNameIn, const string PINIn,const string accountNumberIn):
         firstName(firstNameIn),lastName(lastNameIn),PIN(PINIn),accountNumber(accountNumberIn)   {}

Account::Account(const Account &copy) {
    firstName = copy.firstName;
    lastName = copy.lastName;
    PIN = copy.PIN;
    accountNumber = copy.accountNumber;
}

Account::~Account() = default;


// utility method
void Account::print() const {
    cout << "Name       : " << firstName << " " << lastName << endl;
    cout << "Account No : " << accountNumber << endl;
    cout << "PIN        : " << PIN << endl;
}


// Getters
string Account::getFirstName() const {
    return firstName;
}

string Account::getLastName() const {
    return lastName;
}

string Account::getAccountNumber() const {
    return accountNumber;
}

string Account::getPIN() const {
    return PIN;
}


// Setters
void Account::setFirstName(const std::string firstNameIn) {
    firstName = firstNameIn;
}

void Account::setLastName(const std::string lastNameIn) {
    lastName  =lastNameIn;
}

void Account::setAccountNumber(const std::string accountNumberIn) {
    accountNumber = accountNumberIn;
}

void Account::setPIN(const std::string PINIn) {
    PIN = PINIn;
}