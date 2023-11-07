#include <iostream>
#include <string>
#define SIZE 7      // size of the database
using namespace std;

// menu function
int menu();

// search menu
void  search_menu(const string people_[],const string numbers[]);

// function to search a number
string search(string& name,const string people_[],const string numbers[]);


int main() {
    // seven names of the peoples
    string people[] = {
                        "Adam",
                        "Eva",
                        "Scott",
                        "Williams",
                        "Peter",
                        "Bolivar",
                        "Washington"
                        };

    // seven relevant phone numbers
    string phoneNumbers[] = {
                             "7708963541",
                             "7702569874",
                             "6783695284",
                             "4046589785",
                             "7702583698",
                             "4042581397",
                             "6789851425"
                            };


    // hold the user input for each round
    int user_input;
    // Phone book driver code

    do {
        user_input = menu();    // show menu and get the input and returns it

        // handle the input = 1 case
        if (user_input == 1) search_menu(people,phoneNumbers);


    } while (user_input != 2);      // run until suer entered 2 (Exit)

    return 0;
}


int menu(){
    // print the message t the user
    cout << "----------------Phone Book----------------\n\n";
    cout << "1 - Search for a phone number\n";
    cout << "2 - Exit\n";
    cout << "Enter your choice : " ;

    int user_choice;

    // get the input from the user
    cin >> user_choice;
    return user_choice; // return that value

}


// search menu
void  search_menu(const string people_[],const string numbers[]){
    // get the name from the user
    string entry_name;
    int search_menu_input;

    do {
        cout << "Enter the name of the contact : ";
        cin >> entry_name;      // get the name from the user

        string result = search(entry_name,people_,numbers);
        if (!result.empty()){
            cout << "Contact found!\n";

            cout <<"\tName  : "<<  entry_name << "\n\tPhone : " << result << endl<< endl;
            return;
        }

        cout << "No match found ! " << endl << endl;
        cout << "1 - search again\n0 - Exit to Main Menu" << endl;
        cout << "Enter your choice : ";
        cin >> search_menu_input;


    } while (search_menu_input != 0);
}


string search(string& name,const string people_[],const string numbers[]){

    // loop through the people list first
    for (int i = 0; i < SIZE; ++i) {
        if (people_[i] == name){         // check the given name is sam as the current seeking name
            return numbers[i];
        }
    }

    return ""; // returns empty string if not found
}