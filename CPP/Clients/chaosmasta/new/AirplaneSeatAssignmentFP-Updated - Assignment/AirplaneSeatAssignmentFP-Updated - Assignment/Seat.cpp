#include <string>
#include "Constants.h"

using namespace std;

//***
//*** Copy your class definition code from Seat.h here.
//***
class Seat {
    private:
    string passengerName;
    public:
    string passengerName(){
        
        }

    }



//***
//*** Create a no-arg constructor for class "Seat".
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//*** The one line of code in the constructor invokes method
//***    "setPassengerName" passing the Empty Seat Constant as
//***    the one argument.
//***
Seat(){
setPassengerName(EMPTY_SEAT); 
}





//***
//*** Create a getter for property "passengerName" that returns the
//***    value of the property.
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//*** NOTE: Don't forget to include the const keyword at the end of
//***       the method header just like you did in the prototype.
//***
getPassengerName() {
    return passengerName;
}

//***
//*** Create a setter for property "passengerName" that assigns the
//***    parameter variable to the property.
//***
//*** NOTE: Don't forget to use the class name and scope resolution
//***       operator. See Chapter 9.6.
//*** REMEMBER: setters do not return anything.
//***
setPassengerName(passengerName);
