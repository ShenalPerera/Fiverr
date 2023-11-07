#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double a,b,c,disc,root1, root2;

    cout << "This program calculates the roots of a\n";
    cout << "   quadratic equation of the form\n";
    cout << "            2\n";
    cout << "          ax + bx + c = 0\n\n";

    cout << "Please enter values for a, b, and c: ";
    cin >> a >> b >> c;

    if (a == 0.0 && b == 0.0)
        cout << "The equation is degenerate and has no roots.\n";
    else if (a == 0.0)
        cout << "The equation has the single root x = "
             << -c/b << endl;
    else
    {
        disc = pow(b,2.0) - 4 * a * c;  // calculate discernment
        if (disc > 0.0){
            disc = sqrt(disc);
            root1 = (-b + disc) / (2 * a);
            root2 = (-b - disc) / (2 * a);
            cout << "The two real roots are " << root1 << " and" << root2 << endl;
        }

        else if (disc < 0.0){
            disc = sqrt(abs(disc));
            root1 = (-b ) / (2 * a);
            root2 = (-b ) / (2 * a);
            disc = disc/(2 * a);
            cout << "The two imaginary roots are " << root1 << " + " << disc << "i and "
                                                   << root2 << " + " << disc << "i\n";
        }
        else{
            cout << "Both roots are equal to " << (-b) / (2 * a) << endl;
        }
    }
    return 0;
}