#include "DoubleSubscriptedArray.h"
#include <stdexcept>
using namespace std;

//default constructor for class DoubleSubscriptedArray (default size 1)
DoubleSubscriptedArray::DoubleSubscriptedArray(int numRow, int numCol)
	: size( (numRow > 0 && numCol > 0) ? (numRow * numCol) : 
		throw invalid_argument("Both the number of rows and columns must be greater than 0")),
	ptr(new int[size])
{
	for (size_t i = 0; i < size; ++i) {
		ptr[i] = 0;
	}
}

//copy constructor for class DoubleSubscriptedArray
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& arrayToCopy)
	: size(arrayToCopy.size),
	ptr(new int[size])
{
	for (size_t i = 0; i < size; ++i) {
		ptr[i] = arrayToCopy.ptr[i];
	}
}

//destructor for class DoubleSubscriptedArray
DoubleSubscriptedArray::~DoubleSubscriptedArray() {
	delete [] ptr; //release pointer-based array space
}

int& DoubleSubscriptedArray::operator()(int r, int c) {

}

int DoubleSubscriptedArray::operator()(int r, int c) const {

}