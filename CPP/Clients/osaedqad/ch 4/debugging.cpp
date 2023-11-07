// Debugging: debugging.cpp
#include <iostream>
using namespace std;

int main()
{
    int row = 8;
    int side;

    while ( row > 0 )
    {
        side = 8;

        if ( row % 2 == 1 )
            cout << " ";

        while ( side-- > 0 )
            cout << "* ";

        cout << endl;
        row--;
    } // end while

} // end main