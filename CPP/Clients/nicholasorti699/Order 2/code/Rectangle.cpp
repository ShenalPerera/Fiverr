#include "Rectangle.h"

Rectangle::Rectangle() {
    this->yCoordinate = 0.0;
    this->xCoordinate = 0.0;
    this->length = 0.0;
    this->width = 0.0;
};

Rectangle::Rectangle(float x, float y, float _length, float _width) {
    this->xCoordinate = x;
    this->yCoordinate = y;
    this->length = _length;
    this->width = _width;
}

void Rectangle::setCoordinates(float x, float y) {
    this->xCoordinate = x;
    this->yCoordinate = y;
}

void Rectangle::setSides(float new_length, float new_width) {
    if (new_length < 0){
        throw negativeSide("Length is negative");
    }
    if (new_width < 0){
        throw negativeSide("Width is negative");
    }
    this->length = new_length;
    this->width = new_width;
}

float Rectangle::getXCoordinates() const {
    return xCoordinate;
}

float Rectangle::getYCoordinates() const {
    return yCoordinate;
}

float Rectangle::getLength() const {
    return length;
}

float Rectangle::getWidth() const {
    return width;
}

float Rectangle::area() const {
    if (length < 0){
        throw negativeSide("Length is negative");
    }
    if (width < 0){
        throw negativeSide("Width is negative");
    }
    return length * width;
}

float Rectangle::perimeter() const {
    if (length < 0){
        throw negativeSide("Length is negative");
    }
    if (width < 0){
        throw negativeSide("Width is negative");
    }
    return 2 * (length + width);
}

negativeSide::negativeSide(std::string error_message) {
    this->message = error_message;
}

string negativeSide::getMessage() const {
    return message;
}