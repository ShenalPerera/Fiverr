// Debugging: debugging.cpp

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int i = 1;
    int j;
    int a;
    int b;



    for ( i; i <= 2; i++ ){
        cout << "i is now equal to " << i << endl;

        for (j = 0; j <= 3; j++ )
        {
            cout << "\tj is now equal to " << j << endl;

            cout << "\t\ti + j = " << i + j << "\ti - j = "
                 << i - j << endl;
            cout << "\t\ti * j = " << i * j << "\ti ^ j = "
                 << (i & j) << endl;

            if ( j == 0 )
                continue;
            else
            {
                a = i;
                b = j;
                cout << "\t\ti / j = " <<setprecision(2) <<fixed << (double )a / b <<
                "\ti % j = " << a % b << endl;
            } // end else
        } // end for
    }




    cout << "\nThe final values of i and j are: " << i
    << " and " << j << endl;
} // end main