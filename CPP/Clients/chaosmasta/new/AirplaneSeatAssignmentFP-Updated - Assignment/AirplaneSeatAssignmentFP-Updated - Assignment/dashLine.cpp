#include <string>
#include <iostream>
#include "Constants.h"

using namespace std;

void dashLine(size_t lineLength)
{
    for (size_t x = 0; x < lineLength; x++)
        cout << REPEAT_CHAR;

    cout << endl;
}