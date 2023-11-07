#include <string>

using namespace std;

string upperCase(string string2Upper)
{
    string stringUpperCased;

    for (size_t x = 0; x < string2Upper.length(); x++) {
        stringUpperCased += toupper(string2Upper[x]);
    }

    return stringUpperCased;
}