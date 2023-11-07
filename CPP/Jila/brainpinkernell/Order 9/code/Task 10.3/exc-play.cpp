#include <iostream>
#include <exception>

using namespace std;

int main(){
    int user_choice;

    // get the user's value
    cout << "1 - Check the Logic error\n";
    cout << "2 - Check the Runtime error\n";
    cout << "3 - Non exception part\n";

    cin >> user_choice;

    try {
        if (user_choice == 1) throw invalid_argument("1 is an invalid argument");
        else if (user_choice == 2) throw range_error("2 is a runtime error exception");
        else{
            cout << "This is error free code part\n";
        }
    }
    catch (invalid_argument & e) {
        cerr << "\""<< e.what() << "\" is caught from the program\n";
    }
    catch (range_error & e) {
        cerr << "\"" <<e.what() << "\" is caught from the program\n";
    }

    cout << "This part is executed after the last catch block\n";

    return 0;
}