//*** This is a compiler preprocessor directive which makes it so that only
//***    one copy of the source code file is included in the compilation.
//*** See https://en.wikipedia.org/wiki/Pragma_once
#pragma once

#include "Seat.h"

using namespace std;
class Plane{

private:
    Seat** seats = nullptr;
    int numberOfRows;
    int numberOfLetters;

    void setSeats(int , int);
    void setNumberOfRows(int);
    void setNumberOfLetters(int );
    void loadPlane();

public:
    Plane(int , int);
    int getNumberOfRows() const;
    int getNumberOfLetters() const;
    Seat** getSeats() const;
    bool assignSeat(Plane,string,string);

};
//***
//*** Declare a new class named "Plane".
//*** Declare a private member section.
//***    1) Define the following properties:
//***       A) Include this line of code exactly:
//***             Seat** seats = nullptr;
//***       B) Declare an int variable named "numberOfRows".
//***       C) Declare an int variable named "numberOfLetters".
//***    2) Define the following method prototypes:
//***       A) Define a setter method prototype for property "seats" that
//***             takes two int arguments.
//***       B) Define a setter method prototype for property "numberOfRows".
//***       C) Define a setter method prototype for property "numberOfLetters".
//***          REMEMBER: setters do not return anything.
//***       D) Define a method named "loadPlane" that takes no arguments and
//***             returns no value.
//*** Declare a public member section with the following method prototypes:
//***    1) Define a constructor prototype that takes two int arguments.
//***    2) Define a getter method prototype for property "numberOfRows".
//***       A) Include the const keyword at the end of the prototype making
//***             it a Constant Member Function.
//***       B) Read (or reread) Chapter 10.6 and, in your program comments for
//***             this code, explain why this is a good technique.
//***    3) Define a getter method prototype for property "numberOfLetters".
//***       A) Include the const keyword at the end of the prototype making
//***             it a Constant Member Function.
//***       B) Read (or reread) Chapter 10.6 and, in your program comments for
//***             this code, explain why this is a good technique.
//***    4) Define a getter method prototype for property "seats".
//***       A) Use the following as the return datatype:
//***             Seat**
//***       B) Include the const keyword at the end of the prototype making
//***             it a Constant Member Function.
//***       C) Read (or reread) Chapter 10.6 and, in your program comments for
//***             this code, explain why this is a good technique.
//***    5) Define a method prototype named "assignSeat" takes three arguments
//***             and returns a bool.
//***       A) The three arguments are of the following datatypes and in
//***             this order:
//***          a) Plane
//***          b) string
//***          c) string
//***