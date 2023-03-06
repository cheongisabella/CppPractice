#include "Rectangle.h"
#include <stdexcept>
#include <iostream>
using namespace std;

//Constructor function to initiialise private data
//Default values are 1.0 (see class definition)
Rectangle::Rectangle(float l, float w) { 
	setLength(l);
	setWidth(w);
}

float Rectangle::perimeter() {
	return 2 * getLength() + 2 * getWidth();
}

float Rectangle::area() {
	return getLength() * getWidth();
}

float Rectangle::getLength() const {
	return length;
}

float Rectangle::getWidth() const {
	return width;
}

void Rectangle::setLength(float l) {
	if (l > 0 && l < 20) {
		length = l;
	}
	else {
		throw invalid_argument("Length has to be floating point number between 0.0 and 20.0");
	}
}

void Rectangle::setWidth(float w) {
	if (w > 0 && w < 20)
		width = w;
	else
		throw invalid_argument("Width has to be floating point number between 0.0 and 20.0");
}

void Rectangle::printDetails() {
	cout << "Rectangle r has length " << getLength() << " width " << getWidth() \
		<< " area " << area() << " perimeter " << perimeter() << endl;
}