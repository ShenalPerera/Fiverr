#include <iostream>

using namespace std;

int main(){
    int E;
    int R1;
    int R2;

    cout << "Enter the E (Volts) : ";
    cin >> E;

    cout << "Enter the R1 (Ohms) : ";
    cin >> R1;

    cout << "Enter the r2 (Ohms) : ";
    cin >> R2;

    double I = E/(double )(R1 + R2);
    double V2 = I * R2;
    double P2 = I * V2;

    cout << "I = " << I << endl;
    cout << "V2 = " << V2 << endl;
    cout << "P2 = " << P2 << endl;
    return 0;
}