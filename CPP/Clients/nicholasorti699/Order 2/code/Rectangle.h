#ifndef CODE_RECTANGLE_H
#define CODE_RECTANGLE_H

#include <string>

using namespace std;

class Rectangle {
    // Data fields of the rectangle
private:
    float xCoordinate;
    float yCoordinate;
    float length;
    float width;

public:
    // Default constructor
    Rectangle();

    // overloaded constructor
    Rectangle(float x,float y, float _length, float _width);

    // Mutators
    void setCoordinates(float x, float y);  // Set the x and y coordinates
    void setSides(float new_length, float new_width); // sets the length and width filed

    // Accessors
    float getXCoordinates() const;
    float getYCoordinates() const;
    float getLength() const;
    float getWidth() const;
    float area() const; // given the area of the rectangle
    float perimeter() const; // gives the perimeter of the rectangle

};

class negativeSide{
private:
    string message;

public:
    // Constructor
    negativeSide(string error_message);

    string getMessage() const;
};

#endif //CODE_RECTANGLE_H
