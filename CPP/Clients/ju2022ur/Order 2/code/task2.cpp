#include <iostream>
#define USERS_COUNT 5

using namespace std;

// validate the user is authored or not
bool isAuthorized(string username, string password, string usernames[], string passwords[]);


int main(){
    // Username array
    string usernames[] = {"shenal","superman_12","user1234","batman2","maker45"};
    string passwords[] = {"shenal1234","123456","11223344","rew1234","make123"};

    string username;
    string password;

    cout << "Welcome to the secret portal\n";
    cout << "----------------------------\n";

    cout << "Enter your username : ";
    cin >> username;

    cout << "Enter your password : ";
    cin >> password;

    int count = 0;
    bool authorized = isAuthorized(username,password,usernames,passwords);

    while (count < 2 && !authorized){
        cout << "Enter your username : ";
        cin >> username;

        cout << "Enter your password : ";
        cin >> password;

        authorized = isAuthorized(username,password,usernames,passwords);
        count++;
    }

    if (count >= 2){
        cout << "\nYou exceed the limit. You are not selected\n";
    }
    else{
        cout << "\nYou won the price\n";
    }

    return 0;
}


bool isAuthorized(string username, string password, string usernames[], string passwords[]){

    for (int i = 0; i < USERS_COUNT; ++i) {
        if (username == usernames[i]){

            if (password != passwords[i]){
                cout << "Incorrect password\n";
                return false;
            }
            else{
                return true;
            }
        }
    }

    cout << "User not found\n";
    return false;
}