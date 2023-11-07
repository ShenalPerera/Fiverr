// Debugging: time.cpp
#include <iostream>

#include <ctime>
using namespace std;

void generateTime( int&, int&, int& );
void printUniversal( int, int, int );
void printStandard( int, int, int );
bool morning( int );
bool afterNoon( int );

int main()
{
    int hour; // hour variable
    int minute; // minute variable
    int second; // second variable

    srand( time(nullptr) );

    generateTime( hour, minute, second );

    printUniversal( hour, minute, second );
    printStandard( hour, minute, second );
} // end main

void generateTime( int &h, int &m, int &s )
{
    h = rand() % 24 + 0;
    m = rand() % 48 + 0;
    s = rand() % 60 + 0;
}

void printUniversal( int h, int m, int s )
{
    cout << ( h < 10 ? "0" : "" ) << h << ":";
    cout << ( m < 10 ? "0" : "" ) << m << ":";
    cout << ( s < 10 ? "0" : "" ) << s << endl;
}

void printStandard( int h, int m, int s )
{
    cout << ( h % 12 < 10 ? "0" : "" ) << h % 12 << ":";
    cout << ( m < 10 ? "0" : "" ) << m << ":";
    cout << ( s < 10 ? "0" : "" ) << s << " ";
    if ( morning( h))
        cout << "AM" << endl;
    if ( afterNoon( h ))
        cout << "PM" << endl;
}

bool morning( int h)
{
    return h < 12;
}

bool afterNoon( int h )
{
    return h >= 12;
}