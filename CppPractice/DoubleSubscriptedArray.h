#ifndef TEST_CH18EX7
#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class DoubleSubscriptedArray {

	friend std::ostream& operator<<(std::ostream &, const DoubleSubscriptedArray &);
	friend std::istream& operator>>(std::istream&, DoubleSubscriptedArray&);

public:
	explicit DoubleSubscriptedArray(int = 2, int = 2);
	DoubleSubscriptedArray(const DoubleSubscriptedArray &); //copy constructor 
	~DoubleSubscriptedArray(); //destructor
	size_t getSize() const;

	const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray &); //assignment operator 
	bool operator==(const DoubleSubscriptedArray&) const; //equality operator
	//inequality operator, returns opposite of == operator
	bool operator!=(const DoubleSubscriptedArray &right) const {
		return !(*this == right); //invokes DoubleSubscriptedArray::operator==
	} 

	//double subcript operator for non-const objects returns modifiable lvalue
	int& operator()(int, int); 

	//double subscript operator for const objects returns non-modifiable rvalue
	int operator()(int, int) const; 

private:
	size_t size;
	int* ptr;
	int row;
	int col;
};

#endif
#endif
