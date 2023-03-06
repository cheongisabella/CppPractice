#include "Rectangle.h"
#include <iostream>
#include <stdexcept>
#ifdef TESTING
using namespace std;


int main() {
	Rectangle r; //create Rectangle object

	r.printDetails();

	r.setLength(10.5);
	r.setWidth(7.2);
	r.printDetails();

	try {
		r.setLength(20);
	}
	catch (invalid_argument& e) {
		cerr << "Exception: " << e.what() << endl;
	}

	try {
		r.setWidth(0);
	}
	catch (invalid_argument& e) {
		cerr << "Exception: " << e.what() << endl;
	}

	r.printDetails();
}
#endif