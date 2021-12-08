//*** This is a compiler preprocessor directive which makes it so that only
//***    one copy of the source code file is included in the compilation.
//*** See https://en.wikipedia.org/wiki/Pragma_once
#pragma once

#include <string>

using namespace std;

const int LETTER_OFFSET = (int)'A';
const int NUM_SEAT_LETTERS = 4;
const char SEAT_TYPE_INDEX[NUM_SEAT_LETTERS]{ 'A', 'B', 'C', 'D' };

const string EMPTY_SEAT = "<EMPTY>";

const string HEADER_TEXT = "Airline Seating Assignment Program";
const size_t DASH_LENGTH = HEADER_TEXT.length();
const string PASSENGER_HEADING = "Passenger";
const string SEAT_HEADING = "Seat";

const char MENU_CREATE_MANIFEST = '1';
const char MENU_CREATE_SEATING_CHART = '2';
const char MENU_FIND_PASSENGER = '3';
const char MENU_SHOW_OCCUPANT = '4';
const char MENU_ASSIGN_SEAT = '5';
const char MENU_REMOVE_PASSENGER = '6';
const char MENU_MOVE_PASSENGER = '7';
const char MENU_REQUEST_WINDOW = '8';
const char MENU_REQUEST_AISLE = '9';
const char MENU_EXIT_PROGRAM = 'E';
const char MENU_CLEAR_SCREEN = 'C';

const string CLEAR_SCREEN_MESSAGE = ". Clear Screen and Refresh Full Menu";
const string EXIT_PROGRAM_MESSAGE = ". Exit Program";
const string ENTER_CHOICE_MESSAGE = "Enter your choice: ";
const string CREATE_MANIFEST_MESSAGE = ". Create Manifest";
const string CREATE_SEATING_CHART_MESSAGE = ". Create Seating Chart";
const string FIND_PASSENGER_MESSAGE = ". Find Passenger (by name)";
const string SHOW_OCCUPANT_MESSAGE = ". Show Seat Occupant (by seat)";
const string ASSIGN_SEAT_MESSAGE = ". Assign Seat (by name)";
const string REMOVE_PASSENGER_MESSAGE = ". Remove Passenger (by name)";
const string MOVE_PASSENGER_MESSAGE = ". Move Passenger (by name)";
const string REQUEST_WINDOW_MESSAGE = ". Request Window (by name)";
const string REQUEST_AISLE_MESSAGE = ". Request Aisle (by name)";
const string FOUND_PASSENGER_MESSAGE = " is assigned seat ";
const string NOT_FOUND_PASSENGER_MESSAGE = " does not have an assigned seat";
const string FOUND_OCCUPANT_MESSAGE = " is occupied by ";
const string NOT_FOUND_OCCUPANT_MESSAGE = " is empty";
const string ASSIGNED_SEAT_TO_PASSENGER_MESSAGE = FOUND_PASSENGER_MESSAGE;
const string NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE = " cannot be assigned seat ";
const string INVALID_CHOICE_ERROR_MESSAGE = "Please enter a valid choice: ";
const string REMOVED_PASSENGER_MESSAGE = " was removed from seat ";
const string NOT_REMOVED_PASSENGER_MESSAGE = " was not removed from seat ";
const string NO_AISLE_SEATS_AVAILABLE_MESSAGE = "There are no aisle seats available";
const string NO_WINDOW_SEATS_AVAILABLE_MESSAGE = "There are no window seats available";
const string AISLE_SEATS_AVAILABLE_MESSAGE = " is an available aisle seat";
const string WINDOW_SEATS_AVAILABLE_MESSAGE = " is an available window seat";
const string ERROR_MESSAGE_PREFIX = "***";
const string INVALID_SEAT_LENGTH_MESSAGE = "Invalid seat length";
const string INVALID_SEAT_ROW_OUT_OF_RANGE_LOWER_MESSAGE = "Invalid seat row -- out of range - less than ";
const string INVALID_SEAT_ROW_OUT_OF_RANGE_UPPER_MESSAGE = "Invalid seat row -- out of range - greater than ";
const string INVALID_SEAT_ROW_NON_NUMERIC_MESSAGE = "Invalid seat row -- non-numeric";
const string INVALID_SEAT_LETTER_NON_ALPHABETIC = "Invalid seat letter -- non-alphabetic";
const string INVALID_SEAT_LETTER_OUT_OF_RANGE = "Invalid seat letter - must be ";
const string INVALID_PASSENGER_NAME_MESSAGE = "Invalid passenger name";

const string FIND_PASSENGER_PROMPT = "Please enter the passenger's name: ";
const string SEAT_PROMPT = "Please enter the seat number (format = NNA e.g. 02C): ";

const int SEAT_ROWS_START = 1;
const int SEAT_ROWS_END = 4;
const int NUM_SEAT_ROWS = SEAT_ROWS_END - SEAT_ROWS_START + 1;

const int SEAT_STR_ROW_START_POS = 0;
const int SEAT_STR_LETTER_START_POS = 2;
const int SEAT_STR_ROW_NUM_DIGITS = 2;
const int SEAT_STR_LETTER_NUM_CHARS = 1;

const char REPEAT_CHAR = '-';
const char PAD_CHAR = '0';

const int DISPLAY_WIDTH_CM = 15;
const int NUM_DISPLAY_COLS_CM = 2;
const int DISPLAY_WIDTH_CSC = 10;
const int NUM_DISPLAY_COLS_CSC = 5;
const string ROW_HEADING = "row ";
const string ROW_HEADING_SUFFIX = ":";

const int NUM_WINDOW_SEAT_LETTERS = 2;
const int NUM_AISLE_SEAT_LETTERS = 2;
const int WINDOW_SEAT_INDEX[NUM_WINDOW_SEAT_LETTERS]{ 0, 3 };
const int AISLE_SEAT_INDEX[NUM_AISLE_SEAT_LETTERS]{ 1, 2 };
