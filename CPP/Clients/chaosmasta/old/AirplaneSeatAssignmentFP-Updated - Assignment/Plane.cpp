#include <string>
#include <iostream>

#include "Constants.h"
#include "Seat.h"
#include "upperCase.h"

using namespace std;

//***
//*** Copy your class definition code from Plane.h here.
//***


//***
//*** Create a two-arg constructor for class "Plane".
//***    1) The two arguments are named the following and in this order:
//***       A) "numOfRows"
//***       B) "numOfLetters"
//***    2) The code in the constructor is as follows:
//***       A) Invoke method "setNumberOfRows" passing variable "numOfRows" as
//***             an argument.
//***       B) Invoke method "setNumberOfLetters" passing variable
//***             "numOfLetters" as an argument.
//***       C) Invoke method "setSeats" passing variables "numOfRows"
//***             and "numOfLetters" as arguments.
//***       D) Invoke method "loadPlane" passing no arguments.
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//***


//***
//*** Create a getter for property "numberOfRows" that returns the
//***    value of the property.
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//*** NOTE: Don't forget to include the const keyword at the end of
//***       the method header just like you did in the prototype.
//***


//***
//*** Create a getter for property "numberOfLetters" that returns the
//***    value of the property.
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//*** NOTE: Don't forget to include the const keyword at the end of
//***       the method header just like you did in the prototype.
//***


//***
//*** Create a getter for property "seats" that returns the
//***    value of the property.
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//*** NOTE: Don't forget to include the const keyword at the end of
//***       the method header just like you did in the prototype.
//***


//***
//*** Create a setter for property "numberOfRows" that assigns the
//***    parameter variable to the property.
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//*** REMEMBER: setters do not return anything.
//***


//***
//*** Create a setter for property "numberOfLetters" that assigns the
//***    parameter variable to the property.
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//*** REMEMBER: setters do not return anything.
//***


//***
//*** Create a setter for property "seats" that contains the
//***    the following code:
//***    1) Include this line of code exactly:
//***          seats = new Seat*[numOfRows];
//***
//***       NOTE: Property "seats" is an array of pointers to arrays
//***             (this is what Seat** means).
//***
//***             The line of code in Step 1 allocates memory for a new
//***             array of pointers that contains "numOfRows" elements.
//***             Each of these elements is a pointer to an array of
//***             datatype class "Seat".
//***
//***             Therefore, property "seats" can be referenced using
//***             standard 2-D array syntax. (e.g seat[x][y])
//***
//***             See the image file named "Array of Pointers to Arrays.png"
//***             downloadable in Moodle which is an illustration of this
//***             concept.
//***
//***    2) Write a for-loop that iterates from zero to one less than
//***          variable "numOfRows" times.
//***    3) There is one line of code in the for-loop as follows:
//***       A) Use the loop control variable from Step 2 as an index into
//***             array property "seats".
//***       B) Assign the following to Step 3A:
//***          a) Use the "new" operator to allocate an array of class "Seat"
//***                that contains variable "numOfLetters" elements.
//***             HINT: The expression in Step 3Ba is very close to the code
//***                   given in Step 1 but without the *.
//***       
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//*** REMEMBER: setters do not return anything.
//***


//***
//*** Create a method named "assignSeat".
//***    1) The three arguments are named the following and in this order:
//***       A) "plane"
//***       B) "seat"
//***       C) "passengerName"
//***    2) The method contains the following code:
//***       A) Declare a bool variable named "assignSeatOK" and assign
//***             to it the value of false.
//***       B) Uppercase the parameter variable "seat" using the upperCase
//***             function (code given to you in upperCase.cpp).
//***       C) Include the following two lines of code exactly:
//***             	int rowNum = stoi(seat.substr(0, 2)) - 1;
//***               int letterIndex = seat.at(2) - LETTER_OFFSET;
//***       D) Define a variable of datatype Seat** named "seats".
//***       E) Assign the following to Step 2D:
//***          a) Invoke the method "getSeats" using the reference
//***                variable "plane".
//***       F) Considering that variable "seats" can be referenced using
//***             standard 2-D array syntax as mentioned above, write an
//***             if-statement with the following condition:
//***          a) Index variable "seats" as a 2-D array using the variables
//***                "rowNum" as the first subscript and variable "letterIndex"
//***                as the second subscript. Use this as your reference
//***                variable to invoke the method "getPassengerName".
//***              NOTE: Each element in the 2-D array "seats" is an instance
//***                    of class "Seat". So, each element of this 2-D array
//***                    is a reference variable to an instance of "Seat".
//***          b) Compare Step 2Fa for equality to the Empty Seat Constant.
//***       G) There are two lines of code in the if-statement block in
//***             Step 2F as follows:
//***          a) Invoke the method "setPassengerName" passing the variable
//***                "passengerName" as the argument. Use the same reference
//***                variable from Step 2Fa.
//***          b) Assign the value of true to variable "assignSeatOK".
//***       H) Write a return statement returning the variable "assignSeatOK".
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//***


void Plane::loadPlane() {
	seats[0][0].setPassengerName(EMPTY_SEAT);
	seats[0][1].setPassengerName("Avery");
	seats[0][2].setPassengerName("Daniel");
	seats[0][3].setPassengerName("Luke");

	seats[1][0].setPassengerName("Leo");
	seats[1][1].setPassengerName("Abigail");
	seats[1][2].setPassengerName(EMPTY_SEAT);
	seats[1][3].setPassengerName("Isabella");

	seats[2][0].setPassengerName("Lillian");
	seats[2][1].setPassengerName(EMPTY_SEAT);
	seats[2][2].setPassengerName("Isaac");
	seats[2][3].setPassengerName("Ella");

	seats[3][0].setPassengerName("Evelyn");
	seats[3][1].setPassengerName("Aurora");
	seats[3][2].setPassengerName("Noah");
	seats[3][3].setPassengerName(EMPTY_SEAT);
}