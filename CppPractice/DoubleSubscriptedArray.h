#pragma once
class DoubleSubscriptedArray {
public:
	explicit DoubleSubscriptedArray(int = 1, int = 1);

	int& operator()(int, int); //return element of double-subscripted array to be used as modifiable lvalue
	int operator()(int, int) const; //return element of double-subscripted array as rvalue
private:

};