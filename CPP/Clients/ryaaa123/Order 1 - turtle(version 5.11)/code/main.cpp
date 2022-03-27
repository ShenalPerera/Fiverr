#include <iostream>
//Add the appropriate preprocessor directives here.
//Add the function prototypes here
void initialize(char[][25]);
void display(char[][25]);
void rove(char[][25] , char){

}

using namespace std;
//Globals for the turtle’s current and starting position.
int tr=9;
int tc=9;

int main() {
    char field[25][25];
//    initialize(field);
//    display(field);
    char dir;
    do{
        cout << "\t 8 - Move Up" << endl;
        cout << "\t 2 - Move Down" << endl;
        cout << "\t 4 - Move Left" << endl;
        cout << "\t 6 - Move Right" << endl;
        cout << "\t 0 - Exit" << endl;
        cout << "\t Direction to move: ";
        cin >> dir;
//        if(dir != '0')
            move(field, dir);
    }while(dir != '0');
    return 0;
}

void initialize(char &field){
    cout << ")";
}