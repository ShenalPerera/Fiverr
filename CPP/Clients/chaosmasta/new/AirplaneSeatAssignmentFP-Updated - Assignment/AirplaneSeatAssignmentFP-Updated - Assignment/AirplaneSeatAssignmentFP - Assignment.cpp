#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cctype>

#include "Constants.h"
#include "Plane.h"
#include "dashLine.h"
#include "upperCase.h"

using namespace std;

void displayHeader();
void displayFullMenu();
char getMenuChoice();
void displayShortMenu();
bool isSeatValid(string);
bool isPassengerNameValid(string);
void createManifest(Plane);
void createSeatingChart(Plane);
string findPassenger(string, Plane);
string showOccupant(string, Plane);
bool assignSeat(string, string, Plane);
bool releaseSeat(string, Plane);
string requestWindowAisle(int seatType, Plane plane);
string padRowNum(int);

int main()
{
    const char* WINDOWS_CLEAR_SCREEN = "cls";

    bool exitProgram = false;
    char choice;
    string passengerName;
    string seat;
    string passengerNameToMove;
    string oldSeat, newSeat;

    displayFullMenu();

    //***
    //*** Declare a variable of "Plane" datatype using a name of your
    //**     choosing. This is your reference variable to an instance
    //**     of class "Plane" in which the passengers will be seated.
    //***    I called mine "JMLAir".
    //*** Assign the following to your reference variable:
    //***    Make a call to the two-arg Plane constructor, passing the
    //***    Number of Seat Rows Constant as the first argument and
    //***    the Number of Seat Letters Constant as the second argument.
    //***
    
    //***
    //*** YOUR CODE HERE
    //***
    class Plane {
    public:
    int NUM_SEAT_ROWS;
    string NUM_WINDOW_SEAT_LETTERS;
    };

    Plane JMLAir;
    JMLAir.NUM_SEAT_ROWS = 3;
    JMLAir.NUM_WINDOW_SEAT_LETTERS = " ";

    cout << JMLAir.NUM_SEAT_ROWS << "\n";
    cout << JMLAir.NUM_WINDOW_SEAT_LETTERS;
    return 0;

    
    
    

    do {
        choice = toupper(getMenuChoice());

        switch (choice) {

        case MENU_CREATE_MANIFEST:

            //***
            //*** Call the method "createManifest" passing your
            //***    reference variable to the instance of class "Plane".
            //***

            //***
            //*** YOUR CODE HERE
            //***
            //calling the method and passing the reference variable to class Plane
            createManifest(JMLAir);

            displayShortMenu();

            break;

        case MENU_CREATE_SEATING_CHART:

            //***
            //*** Call the method "createSeatingChart" passing your
            //***    reference variable to the instance of class "Plane".
            //***

            //***
            //*** YOUR CODE HERE
            //***
            
            //calling the method and passing the reference to class Plane
            createSeatingChart(JMLAir);

            displayShortMenu();

            break;

        case MENU_FIND_PASSENGER:
            cout << FIND_PASSENGER_PROMPT;
            getline(cin, passengerName);

            //***
            //*** Assign the following to variable "seat":
            //***    Call the method "findPassenger" passing variable
            //***       "passengerName" as the first argument and your 
            //***       reference variable to the instance of class "Plane"
            //***       as the second argument.
            //***

            //***
            //*** YOUR CODE HERE
            //***
            findPassenger(passengerName, JMLAir);
            cout << endl;

            if (seat != EMPTY_SEAT) {
                dashLine((passengerName + FOUND_PASSENGER_MESSAGE + seat).length());
                cout << passengerName << FOUND_PASSENGER_MESSAGE << seat << endl;
                dashLine((passengerName + FOUND_PASSENGER_MESSAGE + seat).length());
            }
            else {
                dashLine((passengerName + NOT_FOUND_PASSENGER_MESSAGE).length());
                cout << passengerName << NOT_FOUND_PASSENGER_MESSAGE << endl;
                dashLine((passengerName + NOT_FOUND_PASSENGER_MESSAGE).length());
            }

            cout << endl;

            displayShortMenu();

            break;

        case MENU_SHOW_OCCUPANT:
            do {
                cout << SEAT_PROMPT;
                getline(cin, seat);
            } while (!isSeatValid(seat));


            //***
            //*** Assign the following to variable "passengerName":
            //***    Call the method "showOccupant" passing variable "seat"
            //***       as the first argument and your reference variable to
            //***       the instance of class "Plane" as the second argument.
            //***

            //***
            //*** YOUR CODE HERE
            //***
            showOccupant(seat, JMLAir);

            cout << endl;

            if (passengerName != EMPTY_SEAT) {
                dashLine((upperCase(seat) + FOUND_OCCUPANT_MESSAGE + passengerName).length());
                cout << upperCase(seat) << FOUND_OCCUPANT_MESSAGE << passengerName << endl;
                dashLine((upperCase(seat) + FOUND_OCCUPANT_MESSAGE + passengerName).length());
            }
            else {
                dashLine((upperCase(seat) + NOT_FOUND_OCCUPANT_MESSAGE).length());
                cout << upperCase(seat) << NOT_FOUND_OCCUPANT_MESSAGE << endl;
                dashLine((upperCase(seat) + NOT_FOUND_OCCUPANT_MESSAGE).length());
            }

            cout << endl;

            displayShortMenu();

            break;

        case MENU_ASSIGN_SEAT:
            do {
                cout << SEAT_PROMPT;
                getline(cin, seat);
            } while (!isSeatValid(seat));

            do {
                cout << FIND_PASSENGER_PROMPT;
                getline(cin, passengerName);
            } while (!isPassengerNameValid(passengerName));

            cout << endl;

            //***
            //*** Write an if-statement condition as follows:
            //***    Call the method "assignSeat" passing variable "seat" as
            //***       the first argument, variable "passengerName" as the
            //***       second argument and your reference variable to the
            //***       instance of class "Plane" as the third argument.
            //***

            //***
            //*** Place your if-condition in this if-statement.
            //***
            if (assignSeat(seat,passengerName,JMLAir)) {

                dashLine((passengerName + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                cout << passengerName << ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(seat) << endl;
                dashLine((passengerName + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
            }
            else {
                dashLine((passengerName + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                cout << passengerName << NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(seat) << endl;
                dashLine((passengerName + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
            }


            cout << endl;

            displayShortMenu();

            break;

        case MENU_REMOVE_PASSENGER:
            cout << FIND_PASSENGER_PROMPT;
            getline(cin, passengerName);

            //***
            //*** Assign the following to variable "seat":
            //***    Call the method "findPassenger" passing variable
            //***       "passengerName" as the first argument and your
            //***       reference variable to the instance of class "Plane"
            //***       as the second argument.
            //***

            //***
            //*** YOUR CODE HERE
            //***
            findPassenger(passengerName, JMLAir);

            cout << endl;

            if (seat != EMPTY_SEAT) {
                if (releaseSeat(seat, JMLAir)) {
                    dashLine((passengerName + REMOVED_PASSENGER_MESSAGE + seat).length());
                    cout << passengerName << REMOVED_PASSENGER_MESSAGE << seat << endl;
                    dashLine((passengerName + REMOVED_PASSENGER_MESSAGE + seat).length());
                }
                else {
                    dashLine((passengerName + NOT_REMOVED_PASSENGER_MESSAGE + seat).length());
                    cout << passengerName << NOT_REMOVED_PASSENGER_MESSAGE << seat << endl;
                    dashLine((passengerName + NOT_REMOVED_PASSENGER_MESSAGE + seat).length());
                }
            }
            else {
                dashLine((passengerName + NOT_FOUND_PASSENGER_MESSAGE).length());
                cout << passengerName << NOT_FOUND_PASSENGER_MESSAGE << endl;
                dashLine((passengerName + NOT_FOUND_PASSENGER_MESSAGE).length());
            }

            cout << endl;

            displayShortMenu();

            break;

        case MENU_MOVE_PASSENGER:
            cout << FIND_PASSENGER_PROMPT;
            getline(cin, passengerNameToMove);

            //***
            //*** Assign the following to variable "oldSeat":
            //***    Call the method "findPassenger" passing variable
            //***       "passengerNameToMove" as the first argument and your 
            //***       reference variable to the instance of class "Plane"
            //***       as the second argument.
            //***

            //***
            //*** YOUR CODE HERE
            //***
            findPassenger(passengerNameToMove, JMLAir);

            cout << endl;

            if (oldSeat != EMPTY_SEAT) {

                do {
                    cout << SEAT_PROMPT;
                    getline(cin, newSeat);
                } while (!isSeatValid(newSeat));

                cout << endl;

                //***
                //*** Assign the following to variable "passengerName":
                //***    Call the method "showOccupant" passing variable
                //***       "newSeat" as the first argument and your
                //***       reference variable to the instance of class
                //***       "Plane" as the second argument.
                //***

                //***
                //*** YOUR CODE HERE
                //***

                if (passengerName == EMPTY_SEAT) {

                    //***
                    //*** Write an if-statement condition as follows:
                    //***    Call the method "releaseSeat" passing variable
                    //***       "oldSeat" as the first argument and your
                    //***       reference variable to the instance of class
                    //***       "Plane" as the second argument.
                    //***

                    //***
                    //*** Place your if-condition in this if-statement.
                    //***
                    if (releaseSeat(oldSeat, JMLAir)) {

                        dashLine((passengerNameToMove + REMOVED_PASSENGER_MESSAGE + oldSeat).length());
                        cout << passengerNameToMove << REMOVED_PASSENGER_MESSAGE << oldSeat << endl;
                        dashLine((passengerNameToMove + REMOVED_PASSENGER_MESSAGE + oldSeat).length());
                    }
                    else {
                        dashLine((passengerNameToMove + NOT_REMOVED_PASSENGER_MESSAGE + oldSeat).length());
                        cout << passengerNameToMove << NOT_REMOVED_PASSENGER_MESSAGE << oldSeat << endl;
                        dashLine((passengerNameToMove + NOT_REMOVED_PASSENGER_MESSAGE + oldSeat).length());
                    }

                    cout << endl;


                    //***
                    //*** Write an if-statement condition as follows:
                    //***    Call the method "assignSeat" passing variable "newSeat"
                    //***       as the first argument, variable "passengerNameToMove"
                    //***       as the second argument and your reference variable
                    //***       to the instance of class "Plane" as the third argument.
                    //***

                    //***
                    //*** Place your if-condition in this if-statement.
                    //***
                    if (assignSeat(newSeat, passengerNameToMove, JMLAir)) {

                        dashLine((passengerNameToMove + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(newSeat)).length());
                        cout << passengerNameToMove << ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(newSeat) << endl;
                        dashLine((passengerNameToMove + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(newSeat)).length());
                    }
                    else {
                        dashLine((passengerNameToMove + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(newSeat)).length());
                        cout << passengerNameToMove << NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(newSeat) << endl;
                        dashLine((passengerNameToMove + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(newSeat)).length());
                    }
                }

                else {
                    dashLine((passengerNameToMove + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(newSeat)).length());
                    cout << passengerNameToMove << NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(newSeat) << endl;
                    dashLine((passengerNameToMove + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(newSeat)).length());
                }

            }
            else {
                dashLine((passengerNameToMove + NOT_FOUND_PASSENGER_MESSAGE).length());
                cout << passengerNameToMove << NOT_FOUND_PASSENGER_MESSAGE << endl;
                dashLine((passengerNameToMove + NOT_FOUND_PASSENGER_MESSAGE).length());
            }


            cout << endl;

            displayShortMenu();

            break;

        case MENU_REQUEST_WINDOW:

            //***
            //*** Assign the following to variable "seat":
            //***    Call the method "requestWindowAisle" passing the Request
            //***       Window Menu Constant as the first argument and your
            //***       reference variable to the instance of class "Plane"
            //***       as the second argument.
            //***

            //***
            //*** YOUR CODE HERE
            //***
            requestWindowAisle(MENU_REQUEST_WINDOW, JMLAir);

            if (seat != EMPTY_SEAT) {
                dashLine((seat + WINDOW_SEATS_AVAILABLE_MESSAGE).length());
                cout << seat << WINDOW_SEATS_AVAILABLE_MESSAGE << endl;
                dashLine((seat + WINDOW_SEATS_AVAILABLE_MESSAGE).length());

                cout << endl;

                do {
                    cout << FIND_PASSENGER_PROMPT;
                    getline(cin, passengerName);
                } while (!isPassengerNameValid(passengerName));

                cout << endl;

                //***
                //*** Write an if-statement condition as follows:
                //***    Call the method "assignSeat" passing variable "seat" as
                //***       the first argument, variable "passengerName" as the
                //***       second argument and your reference variable to the
                //***       instance of class "Plane" as the third argument.
                //***

                //***
                //*** Place your if-condition in this if-statement.
                //***
                if (assignSeat(seat, passengerName, JMLAir)) {

                    dashLine((passengerName + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                    cout << passengerName << ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(seat) << endl;
                    dashLine((passengerName + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                }
                else {
                    dashLine((passengerName + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                    cout << passengerName << NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(seat) << endl;
                    dashLine((passengerName + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                }
            }
            else {
                dashLine(NO_WINDOW_SEATS_AVAILABLE_MESSAGE.length());
                cout << NO_WINDOW_SEATS_AVAILABLE_MESSAGE << endl;
                dashLine(NO_WINDOW_SEATS_AVAILABLE_MESSAGE.length());
            }

            cout << endl;

            displayShortMenu();

            break;

        case MENU_REQUEST_AISLE:

            //***
            //*** Assign the following to variable "seat":
            //***    Call the method "requestWindowAisle" passing the Request
            //***       Aisle Menu Constant as the first argument and your
            //***       reference variable to the instance of class "Plane"
            //***       as the second argument.
            //***

            //***
            //*** YOUR CODE HERE
            //***
            //calling method requestWindowAisle passing constant and ref variable as second argument.
            requestWindowAisle(MENU_REQUEST_AISLE, JMLAir);


            if (seat != EMPTY_SEAT) {
                dashLine((seat + AISLE_SEATS_AVAILABLE_MESSAGE).length());
                cout << seat << AISLE_SEATS_AVAILABLE_MESSAGE << endl;
                dashLine((seat + AISLE_SEATS_AVAILABLE_MESSAGE).length());

                cout << endl;

                do {
                    cout << FIND_PASSENGER_PROMPT;
                    getline(cin, passengerName);
                } while (!isPassengerNameValid(passengerName));

                cout << endl;

                //***
                //*** Write an if-statement condition as follows:
                //***    Call the method "assignSeat" passing variable "seat" as
                //***       the first argument, variable "passengerName" as the
                //***       second argument and your reference variable to the
                //***       instance of class "Plane" as the third argument.
                //***

                //***
                //*** Place your if-condition in this if-statement.
                //***
                if (assignSeat(seat, passengerName, JMLAir)) {

                    dashLine((passengerName + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                    cout << passengerName << ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(seat) << endl;
                    dashLine((passengerName + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                }
                else {
                    dashLine((passengerName + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                    cout << passengerName << NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(seat) << endl;
                    dashLine((passengerName + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                }
            }
            else {
                dashLine(NO_AISLE_SEATS_AVAILABLE_MESSAGE.length());
                cout << NO_AISLE_SEATS_AVAILABLE_MESSAGE << endl;
                dashLine(NO_AISLE_SEATS_AVAILABLE_MESSAGE.length());
            }

            cout << endl;

            displayShortMenu();

            break;

        case MENU_EXIT_PROGRAM:
            exitProgram = true;
            break;

        case MENU_CLEAR_SCREEN:
            system(WINDOWS_CLEAR_SCREEN);
            displayFullMenu();
            break;

        default:
            cout << INVALID_CHOICE_ERROR_MESSAGE;

        }
    } while (!exitProgram);
}


void displayHeader()
{
    cout << endl;

    dashLine(DASH_LENGTH);

    cout << HEADER_TEXT << endl;

    dashLine(DASH_LENGTH);
}


void displayFullMenu()
{
    displayHeader();

    cout << MENU_CREATE_MANIFEST << CREATE_MANIFEST_MESSAGE << endl;
    cout << MENU_CREATE_SEATING_CHART << CREATE_SEATING_CHART_MESSAGE << endl;
    cout << MENU_FIND_PASSENGER << FIND_PASSENGER_MESSAGE << endl;
    cout << MENU_SHOW_OCCUPANT << SHOW_OCCUPANT_MESSAGE << endl;
    cout << MENU_ASSIGN_SEAT << ASSIGN_SEAT_MESSAGE << endl;
    cout << MENU_REMOVE_PASSENGER << REMOVE_PASSENGER_MESSAGE << endl;
    cout << MENU_MOVE_PASSENGER << MOVE_PASSENGER_MESSAGE << endl;
    cout << MENU_REQUEST_WINDOW << REQUEST_WINDOW_MESSAGE << endl;
    cout << MENU_REQUEST_AISLE << REQUEST_AISLE_MESSAGE << endl;
    dashLine(DASH_LENGTH);
    cout << MENU_EXIT_PROGRAM << EXIT_PROGRAM_MESSAGE << endl;
    dashLine(DASH_LENGTH);
    cout << endl;
    cout << MENU_CLEAR_SCREEN << CLEAR_SCREEN_MESSAGE << endl;
    cout << endl;
    cout << ENTER_CHOICE_MESSAGE;
}


void displayShortMenu()
{
    displayHeader();

    cout << MENU_CLEAR_SCREEN << CLEAR_SCREEN_MESSAGE << endl;
    cout << MENU_EXIT_PROGRAM << EXIT_PROGRAM_MESSAGE << endl;
    cout << endl;
    cout << ENTER_CHOICE_MESSAGE;
}


char getMenuChoice()
{
    char choice;

    cin >> choice;
    cin.ignore();

    cout << endl << endl;

    return choice;
}


bool isSeatValid(string seat)
{
    bool validSeat = true;

    if (seat.length() != (SEAT_STR_ROW_NUM_DIGITS + SEAT_STR_LETTER_NUM_CHARS)) {
        cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_LENGTH_MESSAGE << ERROR_MESSAGE_PREFIX << endl << endl;
        validSeat = false;
    }
    else {
        for (int x = 0; x < SEAT_STR_ROW_NUM_DIGITS; x++) {
            if (!isdigit(seat[x]))
                validSeat = false;
        }
        if (!validSeat) {
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_ROW_NON_NUMERIC_MESSAGE << ERROR_MESSAGE_PREFIX << endl << endl;
        }
    }

    string seatTypeIndexStr = string(SEAT_TYPE_INDEX);

    if (validSeat) {

        if (stoi(seat.substr(SEAT_STR_ROW_START_POS, SEAT_STR_ROW_NUM_DIGITS - SEAT_STR_ROW_START_POS)) < SEAT_ROWS_START) {
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_ROW_OUT_OF_RANGE_LOWER_MESSAGE << SEAT_ROWS_START << ERROR_MESSAGE_PREFIX << endl << endl;
            validSeat = false;
        }
        else if (stoi(seat.substr(SEAT_STR_ROW_START_POS, SEAT_STR_ROW_NUM_DIGITS - SEAT_STR_ROW_START_POS)) > NUM_SEAT_ROWS) {
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_ROW_OUT_OF_RANGE_UPPER_MESSAGE << NUM_SEAT_ROWS << ERROR_MESSAGE_PREFIX << endl << endl;
            validSeat = false;
        }
        else if (!isalpha(seat[SEAT_STR_LETTER_START_POS])) {
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_LETTER_NON_ALPHABETIC << ERROR_MESSAGE_PREFIX << endl << endl;
            validSeat = false;
        }
        else if (seatTypeIndexStr.find(toupper(seat[SEAT_STR_LETTER_START_POS])) == string::npos) {

            // Zero and one based indexing.
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_LETTER_OUT_OF_RANGE << SEAT_TYPE_INDEX[0] << "-" << SEAT_TYPE_INDEX[NUM_SEAT_LETTERS - 1] \
                << ERROR_MESSAGE_PREFIX << endl << endl;
            validSeat = false;
        }
        else
            seat[SEAT_STR_LETTER_START_POS] = toupper(seat[SEAT_STR_LETTER_START_POS]);
    }

    return validSeat;
}


bool isPassengerNameValid(string passengerName) {

    bool validPassengerName = true;

    if (passengerName.find_first_not_of(" ") == passengerName.npos) {
        cout << endl << INVALID_PASSENGER_NAME_MESSAGE << endl << endl;
        validPassengerName = false;
    }

    return validPassengerName;
}


string padRowNum(int row) {
    string seat = "";
    string padding = "";

    seat = to_string(row + 1);
    padding.insert(0, SEAT_STR_ROW_NUM_DIGITS - seat.length(), PAD_CHAR);
    seat = padding + seat;

    return seat;
}


void createManifest(Plane plane)
{
    cout << left;
    cout << setw(DISPLAY_WIDTH_CM) << PASSENGER_HEADING << setw(DISPLAY_WIDTH_CM) << SEAT_HEADING << endl;

    dashLine(DISPLAY_WIDTH_CM * NUM_DISPLAY_COLS_CM);

    Seat** seats = plane.getSeats();

    string seat = "";

    for (int row = 0; row < NUM_SEAT_ROWS; row++) {
        for (int letter = 0; letter < NUM_SEAT_LETTERS; letter++)
            if (seats[row][letter].getPassengerName() != EMPTY_SEAT) {
                seat = padRowNum(row) + string(SEAT_STR_LETTER_NUM_CHARS, SEAT_TYPE_INDEX[letter]);

                cout << setw(DISPLAY_WIDTH_CM) << seats[row][letter].getPassengerName()
                    << setw(DISPLAY_WIDTH_CM) << seat << endl;
            }
    }

    dashLine(DISPLAY_WIDTH_CM * NUM_DISPLAY_COLS_CM);
    cout << endl;
}


void createSeatingChart(Plane plane)
{
    Seat** seats = plane.getSeats();

    cout << left;
    cout << setw(DISPLAY_WIDTH_CSC) << " ";

    for (int letter = 0; letter < NUM_SEAT_LETTERS; letter++)
        cout << setw(DISPLAY_WIDTH_CSC) << SEAT_TYPE_INDEX[letter];

    cout << endl;

    dashLine(DISPLAY_WIDTH_CSC * NUM_DISPLAY_COLS_CSC);

    for (int row = 0; row < NUM_SEAT_ROWS; row++) {
        cout << setw(DISPLAY_WIDTH_CSC) << ROW_HEADING + to_string(row + 1) + ROW_HEADING_SUFFIX;
        for (int letter = 0; letter < NUM_SEAT_LETTERS; letter++)
            cout << setw(DISPLAY_WIDTH_CSC) << seats[row][letter].getPassengerName();
        cout << endl;
    }

    dashLine(DISPLAY_WIDTH_CSC * NUM_DISPLAY_COLS_CSC);

    cout << endl;
}


string findPassenger(string passengerName, Plane plane)
{
    string seat = EMPTY_SEAT;
    bool found = false;
    int letter;
    int row;

    //***
    //*** Define a variable of datatype Seat** named "seats".
    //*** Assign the following to variable "seats":
    //***    Invoke the method "getSeats" using the reference
    //***       variable "plane".
    //***

    //***
    //*** YOUR CODE HERE
    //***
    Seat** = seats;
    getSeats(JMLAir);
    passengerName = upperCase(passengerName);

    //***
    //*** 1) Initialize variable "row" to 0 (zero).
    //*** 2) Write a while-loop with the following compound boolean condition:
    //***       The negation of variable "found" AND OPERATOR variable "row" less
    //***          than the Number of Seat Rows Constant.
    //*** 3) The following code is inside the while-loop in Step 2:
    //***       A) Initialize variable "letter" to 0 (zero).
    //***       B) Write a while-loop with the following compound boolean condition:
    //***          a) The negation of variable "found" AND OPERATOR variable "letter"
    //***             less than the Number of Seat Letters Constant.
    //***
    //***             NOTE: This while-loop is nested inside the first while-loop.
    //***
    //***       C) The following code is inside the nested while-loop in Step 3B:
    //***          a) Write an if-statement condition as follows:
    //***             1) Call method upperCase passing the following as the argument:
    //***                A) Index variable "seats" as a 2-D array using the variable
    //***                   "row" as the first subscript and variable "letter"
    //***                   as the second subscript. Use this as your reference
    //***                   variable to invoke the method "getPassengerName".
    //***
    //***                   NOTE: Each element in the 2-D array "seats" is an instance
    //***                         of class "Seat". So, each element of this 2-D array
    //***                         is a reference variable to an instance of "Seat".
    //***
    //***                B) Compare Step 3Ca1A for equality to the variable "passengerName".
    //***          b) There are two lines of code in the if-statement block in
    //***                Step 3Ca as follows:
    //***             1) Assign the following code to variable "seat" exactly:
    //***                A) padRowNum(row) + string(SEAT_STR_LETTER_NUM_CHARS, SEAT_TYPE_INDEX[letter]);
    //***             2) Assign the value of true to the variable "found".
    //***          c) Increment variable "letter" by one.
    //***       D) Increment variable "row" by one.
    //***

    //***
    //*** YOUR CODE HERE
    //***

    row[0]
    while (! found && letter < NUM_SEAT_LETTERS) {
        letter[0]
        while (! found && letter < NUM_AISLE_SEAT_LETTERS) {
            if upperCase(seats[row][letter]) {
                getPassengerName();
                padRowNum(row) + string(SEAT_STR_LETTER_NUM_CHARS, SEAT_TYPE_INDEX[letter]);
                found = true;
                letter++;
                row++;

            }
        }
    }

    return seat;
}


string showOccupant(string seat, Plane plane)
{
    string passengerName = EMPTY_SEAT;

    seat = upperCase(seat);

    //***
    //*** Define a variable of datatype Seat** named "seats".
    //*** Assign the following to variable "seats":
    //***    Invoke the method "getSeats" using the reference
    //***       variable "plane".
    //***

    //***
    //*** YOUR CODE HERE
    //***
    Seat** = seats;
    getSeats(plane);

    int rowNum = stoi(seat.substr(SEAT_STR_ROW_START_POS, SEAT_STR_ROW_NUM_DIGITS)) - 1;
    int letterIndex = seat.at(SEAT_STR_LETTER_START_POS) - LETTER_OFFSET;

    //***
    //*** Assign the following to variable "passengerName":
    //***    Index variable "seats" as a 2-D array using the variable
    //***       "rowNum" as the first subscript and variable "letterIndex"
    //***       as the second subscript. Use this as your reference
    //***       variable to invoke the method "getPassengerName".
    //***
    //***       NOTE: Each element in the 2-D array "seats" is an instance
    //***             of class "Seat". So, each element of this 2-D array
    //***             is a reference variable to an instance of "Seat".
    //***

    //***
    //*** YOUR CODE HERE
    //***
    [rowNum][letterIndex]
    getPassengerName();
    return passengerName;
}


bool assignSeat(string seat, string passengerName, Plane plane)
{
    bool assignSeatOK = false;

    seat = upperCase(seat);

    //***
    //*** Define a variable of datatype Seat** named "seats".
    //*** Assign the following to variable "seats":
    //***    Invoke the method "getSeats" using the reference
    //***       variable "plane".
    //***

    //***
    //*** YOUR CODE HERE
    //***
    //invoke the method getSeats using reference plane
    Seat** = seats
    getSeats(plane);

    int rowNum = stoi(seat.substr(SEAT_STR_ROW_START_POS, SEAT_STR_ROW_NUM_DIGITS)) - 1;
    int letterIndex = seat.at(SEAT_STR_LETTER_START_POS) - LETTER_OFFSET;

    //***
    //*** Write an if-statement condition as follows:
    //***    1) Index variable "seats" as a 2-D array using the variable
    //***       "rowNum" as the first subscript and variable "letterIndex"
    //***       as the second subscript. Use this as your reference
    //***       variable to invoke the method "getPassengerName".
    //***
    //***       NOTE: Each element in the 2-D array "seats" is an instance
    //***             of class "Seat". So, each element of this 2-D array
    //***             is a reference variable to an instance of "Seat".
    //***
    //***    2) Compare Step 1 for equality to the Empty Seat Constant.
    //***    3) There are two lines of code in this if-statement block:
    //***       A) Index variable "seats" as a 2-D array using the variable
    //***          "rowNum" as the first subscript and variable "letterIndex"
    //***          as the second subscript. Use this as your reference
    //***          variable to invoke the method "setPassengerName" passing
    //***          variable "passengerName" as the one argument.
    //***       B) Assign the value of true to the variable "assignSeatOK".
    //***

    //***
    //*** Place your if-condition in this if-statement.
    //***
    if (seats[rowNum][letterIndex]) {
        
        //***
        //*** Place your code in this if-statement-block.
        //***
        getPassengerName()
        [rowNum][letterIndex]
        setPassengerName(passengerName);
        assignSeatOK = true;
    }

    return assignSeatOK;
}


bool releaseSeat(string seat, Plane plane)
{
    bool releaseSeatOK = true;

    seat = upperCase(seat);

    //***
    //*** Define a variable of datatype Seat** named "seats".
    //*** Assign the following to variable "seats":
    //***    Invoke the method "getSeats" using the reference
    //***       variable "plane".
    //***

    //***
    //*** YOUR CODE HERE
    //***
    Seat** = seats;
    getSeats(plane);

    int rowNum = stoi(seat.substr(SEAT_STR_ROW_START_POS, SEAT_STR_ROW_NUM_DIGITS)) - 1;
    int letterIndex = seat.at(SEAT_STR_LETTER_START_POS) - LETTER_OFFSET;

    //***
    //*** Index variable "seats" as a 2-D array using the variable
    //***    "rowNum" as the first subscript and variable "letterIndex"
    //***    as the second subscript. Use this as your reference
    //***    variable to invoke the method "setPassengerName" passing
    //***    the Empty Seat Constant as the one argument.
    //***
    //***    NOTE: Each element in the 2-D array "seats" is an instance
    //***          of class "Seat". So, each element of this 2-D array
    //***          is a reference variable to an instance of "Seat".
    //***

    //***
    //*** YOUR CODE HERE
    //***
    int seats[rowNum][letterIndex] setPasserngerName(EMPTY_SEAT);

    return releaseSeatOK;
}

string requestWindowAisle(int seatType, Plane plane)
{
    bool requestOK = false;
    int letter;
    int row;
    string seat = EMPTY_SEAT;

    //***
    //*** Define a variable of datatype Seat** named "seats".
    //*** Assign the following to variable "seats":
    //***    Invoke the method "getSeats" using the reference
    //***       variable "plane".
    //***

    //***
    //*** YOUR CODE HERE
    //***
    Seat** = seats;
    getSeats(plane);

    switch (seatType) {

    case MENU_REQUEST_WINDOW:

        //***
        //*** 1) Initialize variable "letter" to 0 (zero).
        //*** 2) Write a while-loop with the following compound boolean condition:
        //***       The negation of variable "requestOK" AND OPERATOR variable
        //***       "letter" less than the Number of Window Seat Letters Constant.
        //*** 3) The following code is inside the while-loop in Step 2:
        //***       A) Initialize variable "row" to 0 (zero).
        //***       B) Write a while-loop with the following compound boolean condition:
        //***          a) The negation of variable "requestOK" AND OPERATOR variable
        //***             "row" less than the Number of Seat Rows Constant.
        //***
        //***             NOTE: This while-loop is nested inside the first while-loop.
        //***
        //***       C) The following code is inside the nested while-loop in Step 3B:
        //***          a) Write an if-statement condition as follows:
        //***             1) Call method upperCase passing the following as the argument:
        //***                A) Index variable "seats" as a 2-D array using the variable
        //***                   "row" as the first subscript and "WINDOW_SEAT_INDEX[letter]"
        //***                   as the second subscript. Use this as your reference
        //***                   variable to invoke the method "getPassengerName".
        //***
        //***                   NOTE: Each element in the 2-D array "seats" is an instance
        //***                         of class "Seat". So, each element of this 2-D array
        //***                         is a reference variable to an instance of "Seat".
        //***
        //***                B) Compare Step 3Ca1A for equality to the Empty Seat Constant.
        //***          b) There are two lines of code in the if-statement block in
        //***                Step 3Ca as follows:
        //***             1) Assign the following code to variable "seat" exactly:
        //***                A) padRowNum(row) + string(SEAT_STR_LETTER_NUM_CHARS, SEAT_TYPE_INDEX[WINDOW_SEAT_INDEX[letter]]);
        //***             2) Assign the value of true to the variable "requestOK".
        //***          c) Increment variable "row" by one.
        //***       D) Increment variable "letter" by one.
        //***
        //***

        //***
        //*** YOUR CODE HERE
        //***
        letter = 0;
        while (! requestOK && letter < NUM_WINDOW_SEAT_LETTERS) {
            row = 0;
            while (! requestOK && row < NUM_SEAT_ROWS) {
                if(upperCase(seats[row]WINDOW_SEAT_INDEX[letter] getPassengerName())) {
                    padRowNum(row) + string(SEAT_STR_LETTER_NUM_CHARS, SEAT_TYPE_INDEX[WINDOW_SEAT_INDEX[letter]]);
                    requestOK = true;
                    row++;
                    letter++;
                }
            }
        }

        break;

    case MENU_REQUEST_AISLE:

        //***
        //*** 1) Initialize variable "letter" to 0 (zero).
        //*** 2) Write a while-loop with the following compound boolean condition:
        //***       The negation of variable "requestOK" AND OPERATOR variable
        //***       "letter" less than the Number of Aisle Seat Letters Constant.
        //*** 3) The following code is inside the while-loop in Step 2:
        //***       A) Initialize variable "row" to 0 (zero).
        //***       B) Write a while-loop with the following compound boolean condition:
        //***          a) The negation of variable "requestOK" AND OPERATOR variable
        //***             "row" less than the Number of Seat Rows Constant.
        //***
        //***             NOTE: This while-loop is nested inside the first while-loop.
        //***
        //***       C) The following code is inside the nested while-loop in Step 3B:
        //***          a) Write an if-statement condition as follows:
        //***             1) Call method upperCase passing the following as the argument:
        //***                A) Index variable "seats" as a 2-D array using the variable
        //***                   "row" as the first subscript and "AISLE_SEAT_INDEX[letter]"
        //***                   as the second subscript. Use this as your reference
        //***                   variable to invoke the method "getPassengerName".
        //***
        //***                   NOTE: Each element in the 2-D array "seats" is an instance
        //***                         of class "Seat". So, each element of this 2-D array
        //***                         is a reference variable to an instance of "Seat".
        //***
        //***                B) Compare Step 3Ca1A for equality to the Empty Seat Constant.
        //***          b) There are two lines of code in the if-statement block in
        //***                Step 3Ca as follows:
        //***             1) Assign the following code to variable "seat" exactly:
        //***                A) padRowNum(row) + string(SEAT_STR_LETTER_NUM_CHARS, SEAT_TYPE_INDEX[AISLE_SEAT_INDEX[letter]]);
        //***             2) Assign the value of true to the variable "requestOK".
        //***          c) Increment variable "row" by one.
        //***       D) Increment variable "letter" by one.
        //***

    //***
    //*** YOUR CODE HERE
    //***
    letter = 0;
    while(! requestOK && letter < NUM_AISLE_SEAT_LETTERS) {
        row = 0;
        while (! requestOK && letter < NUM_SEAT_ROWS) {
            if (upperCase(seats[row][AISLE_SEAT_INDEX[letter]] getPassengerName()) {
                padRowNum(row) + string(SEAT_STR_LETTER_NUM_CHARS, SEAT_TYPE_INDEX[AISLE_SEAT_INDEX[letter]]);
                requestOK = true;
                row++;
                letter++;
            }
        }
    }
        break;
    }

    return seat;
}