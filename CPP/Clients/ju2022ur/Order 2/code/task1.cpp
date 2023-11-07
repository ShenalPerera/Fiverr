#include <iostream>
#include <cmath>


#define G_ACCELERATION 9.8

using namespace std;

// menu function to show the menu and get the input
int print_menu();

// Function to calculate the last velocity before the surface
double calculateVelocity(double height);

double calculateTime(double height);



int main() {
    cout << "                                  WELCOME TO TIME CALCULATOR\n";
    cout << "--------------------------------------------------------------------------------------------\n";
    cout << "This application will calculate final velocity of a free-falling objects at various beginning heights.\n";
    cout << "============================================================================================\n";

    double height = print_menu();

    // validate the height
    while (height < 0){
        cout << "Invalid input\n";
        height = print_menu();
    }

    cout << "Velocity at the earth surface is " << calculateVelocity(height) << " m/s\n";
    cout << "Time consumed to obtain that velocity is " << calculateTime(height) << "s\n";


    return 0;
}


//=========================== Functions =====================================
// menu function to show the print_menu and get the input
int print_menu(){
    // hold the height from the surface
    int user_height;


    // get the user input
    cout << "Enter the initial height (m) : ";
    cin >> user_height;

    return user_height;
}


// Function to calculate the last velocity before the surface
double calculateVelocity(double height){
    // V^2 = U^2 + 2aS; u=0
    // v = sqrt(2as)

    return sqrt(2 * G_ACCELERATION * height);

}

double calculateTime(double height){
    // s = ut + (1/2)at^2
    // S = 1/2 at ^2
    // t = + sqrt(2s/a)
    return sqrt( ( 2 * height) / G_ACCELERATION);
}


