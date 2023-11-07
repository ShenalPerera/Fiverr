//*** This is a compiler preprocessor directive which makes it so that only
//***    one copy of the source code file is included in the compilation.
//*** See https://en.wikipedia.org/wiki/Pragma_once
#pragma once

#include <string>

using namespace std;

class Seat{
private:
    string passengerName;
public:
    Seat();
    string getPassengerName() const;
    void setPassengerName(string);
};
//***
//*** Declare a new class named "Seat".
//*** Declare a private member section with the following property:
//***    1) Declare a string variable named "passengerName".
//*** Declare a public member section with the following method prototypes:
//***    1) Define a no-arg constructor prototype.
//***    2) Define a getter method prototype for property "passengerName".
//***       A) Include the const keyword at the end of the prototype making
//***             it a Constant Member Function.
//***       B) Read (or reread) Chapter 10.6 and, in your program comments for
//***             this code, explain why this is a good technique.
//***    3) Define a setter method prototype for property "passengerName".
//***       REMEMBER: setters do not return anything.
//***