#include <iostream>
#include <string>
#include <fstream>

#define SIZE 10

using namespace std;

// function to print the menu
void display_menu();

// YN to boolen;
bool YN_to_boolean(char character);

// Initialize the rooms' data
int init_data(string roomNames[], int  roomData[SIZE][3], bool roomStatus[]);

void reserve_room(string roomNames[], int  roomData[SIZE][3], bool roomStatus[],int size);

void release_room(string roomNames[], int  roomData[SIZE][3], bool roomStatus[],int size);

void check_inventory(string roomNames[], int  roomData[SIZE][3], bool roomStatus[],int size);

int main() {

    int currentSize = 6;

    // rooms details are identified by the indexes
    string roomNames[SIZE] ;     // store the names of the rooms
    int roomData[SIZE][3] ;      // store each rooms number, capacity and the reserved days
    bool roomsStatus[SIZE] ;     // include the status of the room


    // initialize the data
    currentSize = init_data(roomNames,roomData,roomsStatus);


    // main driven loop
    int user_input;

    do {
        // show the menu
        display_menu();

        // get the input
        cin >> user_input;

        if (user_input == 1) reserve_room(roomNames,roomData,roomsStatus,currentSize);
        if (user_input == 2) release_room(roomNames,roomData,roomsStatus,currentSize);
        if (user_input == 3) check_inventory(roomNames,roomData,roomsStatus,currentSize);
    } while (user_input != 4);


    return 0;
}


void display_menu(){
    cout << "1 - Reserve a room\n";
    cout << "2 - Return/release an existing reservation\n";
    cout << "3 - Check classroom inventory\n";
    cout << "4 - Exit\n";
}

// YN to boolen;
bool YN_to_boolean(char character){
    return towlower(character) == 'y';
}

// Initialize the rooms' data
int init_data(string roomNames[], int  roomData[SIZE][3], bool roomStatus[]){
    // read the file
    ifstream fin("projectData.dat");

    // show an error message and quit the program if file not found
    if (fin.fail()) {
        cout << "File not found" << endl;
        exit(1);
    }
    string tempName;
    int tempNumber, tempCapacity, tempResDays;

    int i = 0;
    char c;
    while (fin >> tempName){

        fin >> tempNumber;
        fin >> tempCapacity;
        fin >> c;
        fin >> tempResDays;


        roomNames[i] = tempName;
        roomData[i][0] =tempNumber;
        roomData[i][1] = tempCapacity;
        roomData[i][2] = tempResDays;

        roomStatus[i] = YN_to_boolean(c);
        i++;
    }

    return i;
}

void reserve_room(string roomNames[], int  roomData[SIZE][3], bool roomStatus[],int size){
    int seatCount;
    int daysCount;

    cout << "How many seat do you want : ";
    cin >> seatCount;

    cout << "How many days you want    : ";
    cin >> daysCount;

    cout << "\nAvailable rooms" << endl << endl;
    // search the rooms that are available
    for (int i = 0; i < size; ++i) {
        if (roomStatus[i]) continue;

        cout << i + 1 << " - " << roomNames[i] << endl;
    }

    int room_number;
    cout << "Select the room : ";
    cin >> room_number;

    if (roomStatus[room_number-1]) {
        cout << "\nInvalid input!" << endl << endl;
        return;
    }


    if (seatCount > roomData[room_number-1][1]){
        cout << "\nCapacity exceeds!" << endl << endl;
        return;
    }

    roomData[room_number-1][2] =  daysCount;
    roomStatus[room_number-1] = true;

    cout << "Name : " << roomNames[room_number-1] << "| Number : " << roomData[room_number-1][0] << "| Capacity : " <<
    roomData[room_number-1][1] << "| reserve days : " << roomData[room_number-1][2] << endl << endl;
}

void release_room(string roomNames[], int  roomData[SIZE][3], bool roomStatus[],int size){
    int roomNumber;
    string roomName;

    cout << "Enter the room number : ";
    cin >> roomNumber;

    cout << "Enter the room name   : ";
    cin >> roomName;

    bool isFound = false;
    int index;
    for (int i = 0; i < size; ++i) {
        if (roomName == roomNames[i] && roomNumber == roomData[i][0]){
            isFound = true;
            index = i;
            break;
        }
    }

    if (!isFound){
        cout << "\nNo room found!\n" << endl;

    }
    else{
        char c;
        cout << "Enter 'Y' to release the room or any other to discard : ";
        cin >> c;

        if (c == 'Y'){
            roomData[index][2] = 0;
            roomStatus[index] = false;
            cout << "\nRoom is released\n\n";
        }
    }
}

void check_inventory(string roomNames[], int  roomData[SIZE][3], bool roomStatus[],int size){
    // print the rooms detals
    bool isFound = false;
    for (int i = 0; i < size; ++i) {
        if (!roomStatus[i]){
            isFound = true;
            cout << roomNames[i] << " " << roomData[i][0] << " " << roomData[i][1] << endl;
        }
    }

    if (!isFound){
        cout << "\nNo available rooms\n" << endl;
    }
    else{
        char y;
        cout << "Do you like to make a reservation (Y or any other to no) : ";
        cin >> y;

        if ((y == 'Y' || y == 'y')){
            reserve_room(roomNames,roomData,roomStatus,size);
        }
    }

}