#include <iostream>
#include <string>

using namespace std;

int main(){

    int * intPointer;
    double * doublePointer;
    string * stringPointer;

    intPointer = new int;
    doublePointer = new double ;
    stringPointer = new string ;

    *intPointer = 1003;
    *doublePointer = 10.03;
    *stringPointer = "1003";

    cout << "Inter pointer " << intPointer << " holds value " << *intPointer << endl;
    cout << "Double pointer " << doublePointer << " holds value " << *doublePointer << endl;
    cout << "String pointer " << stringPointer << " holds value " << *stringPointer << endl;

    delete intPointer;
    delete doublePointer;
    delete stringPointer;

    return EXIT_SUCCESS;
}
