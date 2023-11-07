#include <iostream>
#define SIZE 18

using namespace std;

// function to check the given item is exits
bool isFound(const int arr[], int user_number);

int main() {
    // numbers array
    int arr [] = {
            5658845,
            4520125,
            7895122,
            8777541,
            8451277,
            1302850,
            8080152,
            4562555,
            5552012,
            5050552,
            7825877,
            1250255,
            1005231,
            6545231,
            3852085,
            7576651,
            7881200,
            4581002
    };


    // menu
    do {
        int user_option;

        cout << "1. Search\n";
        cout << "2. Exit\n";
        cout << "Enter the option : " ;

        cin >> user_option;

        if (user_option == 1) {
            int number;
            cout << "\nEnter the number : ";
            cin >> number;

            if (isFound(arr,number)) cout <<"\nNumber is valid!" << endl;
            else   cout << "\nNumber is invalid" << endl;

        }

        if (user_option == 2) break;



    } while (true);
    return 0;
}


// function to check the given item is exits
bool isFound(const int arr[], int user_number){
    // loop through the list
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == user_number){
            return true;
        }
    }
    return false;
}

