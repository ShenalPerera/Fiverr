#include <iostream>

#include "Rectangle.h"

using namespace std;

int main() {
    float x,y,length,width;
    cout << "Enter the X- coordinate : ";
    cin >> x;

    cout << "Enter the Y- coordinate : ";
    cin >> y;

    cout << "Enter the length : ";
    cin >> length;

    cout << "Enter the width : ";
    cin >> width;

    Rectangle rectangle(x,y,length,width);
    try {
        cout << "Area of the rectangle is : " << rectangle.area() << endl;
        cout << "Perimeter of the rectangle is : " << rectangle.perimeter() << endl;
    }
    catch (negativeSide exp) {
        cout << exp.getMessage() << endl;
    }


    return 0;
}
