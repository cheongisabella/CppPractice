#ifdef TEST_CH18EX7
#include "DoubleSubscriptedArray.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

//default constructor for class DoubleSubscriptedArray (default size 2 * 2)
DoubleSubscriptedArray::DoubleSubscriptedArray(int numRow, int numCol)
	: size( (numRow > 0 && numCol > 0) ? (numRow * numCol) : 
		throw invalid_argument("Both the number of rows and columns must be greater than 0")),
	row(numRow),
	col(numCol),
	ptr(new int[size])
{
	for (size_t i = 0; i < size; ++i) {
		ptr[i] = 0;
	}
}

//copy constructor for class DoubleSubscriptedArray
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& arrayToCopy)
	: size(arrayToCopy.size),
	ptr(new int[size]),
	row(arrayToCopy.row),
	col(arrayToCopy.col)
{
	for (size_t i = 0; i < size; ++i) {
		ptr[i] = arrayToCopy.ptr[i];
	}
}

//destructor for class DoubleSubscriptedArray
DoubleSubscriptedArray::~DoubleSubscriptedArray() {
	delete [] ptr; //release pointer-based array space
}

//return number of elements of DoubleSubscriptedArray
size_t DoubleSubscriptedArray::getSize() const {
	return size;
}

//overloaded assignment operator
const DoubleSubscriptedArray &DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &right)
{
	//avoid self-assignment
	if (&right != this) {
		//for arrays of different sizes, deallocate original left-side array
		//then allocate new left side array
		if (size != right.size) {
			delete[] ptr; //release space
			size = right.size; //resize this object
			row = right.row;
			col = right.col;
			ptr = new int[size]; //create space for DoubleSubscriptedArray copy
		}

		for (size_t i = 0; i < right.size; ++i) {
			ptr[i] = right.ptr[i]; //copy array into object
		}
	}

	return *this; //enables x = y = z;
	
}

//determine if two arrays are equal and return true otherwise false
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &right) const {
	if (size != right.size) {
		return false;
	}
	for (size_t i = 0; i < size; ++i) {
		if (ptr[i] != right.ptr[i]) return false;
	}

	return true;
}


//overloaded double subcript operator for non-const DoubleSubscriptArrays
//reference return creates modifiable lvalue
int& DoubleSubscriptedArray::operator()(int r, int c) {
	//check for subscripts out-of-range error
	if (r < 0 || c < 0 || r >= row || c >= col)
		throw out_of_range("Row or column subscript out of range");
	return ptr[r * col + c]; //reference return
}

//overloaded double subscript operator for const DoubleSubscriptedArrays
//const reference return creates rvalue
int DoubleSubscriptedArray::operator()(int r, int c) const {
	//check for subscripts out-of-range error
	if (r < 0 || c < 0 || r >= row || c >= col)
		throw out_of_range("Row or column subscript out of range");
	return ptr[r * col + c]; //returns copy of this element
}

//overloaded input operator for class DoubleSubscriptedArray
istream &operator>>(istream& input, DoubleSubscriptedArray &a) {
	for (size_t i = 0; i < a.size; ++i) {
		input >> a.ptr[i];
	}

	return input; //enables cin >> x >> y;
}

//overloaded output operator for class DoubleSubscriptedArray
ostream &operator<<(ostream &output, const DoubleSubscriptedArray &a) {
	for (size_t i = 0; i < a.size; ++i) {
		output << setw(12) << a.ptr[i];
		if ((i + 1) % 4 == 0) output << endl; //4 numbers per row of output
	}

	if (a.size % 4 != 0) output << endl; //end last line of output

	return output; //enables cout << x << y;
}


#endif