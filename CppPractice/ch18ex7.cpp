#ifdef TEST_CH18EX7
#include "DoubleSubscriptedArray.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	//constructor initialise a DoubleSubscriptedArray object
	DoubleSubscriptedArray chessBoard1(3, 5); // array representing 3 by 5 board
	DoubleSubscriptedArray chessBoard2; // array representing 2 by 2 board

	//print chessBoard1 size and contents
	cout << "Size of DoubleSubscriptedArray chessBoard1 is "
		<< chessBoard1.getSize()
		<< "\nDoubleSubscriptedArray after initialisation:\n"
		<< chessBoard1;

	//print chessBoard2 size and contents
	cout << "Size of DoubleSubscriptedArray chessBoard2 is "
		<< chessBoard2.getSize()
		<< "\nDoubleSubscriptedArray after initialisation:\n"
		<< chessBoard2;


	// input and print chessBoard1 and chessBoard 2
	cout << "\nEnter 19 integers" << endl;
	cin >> chessBoard1 >> chessBoard2;

	cout << "\nAfter input, the DoubleSubscriptedArrays contain: \n"
		<< "chessBoard1:\n" << chessBoard1
		<< "chessBoard2:\n" << chessBoard2;

	// use overloaded inquality (!=) operator
	cout << "\nEvaluating: chessBoard1 != chessBoard2" << endl;

	if (chessBoard1 != chessBoard2)
		cout << "chessBoard1 and chessBoard2 are not equal" << endl;

	// create DoubleSubscriptedArray chessBoard3 using chessBoard1 as an
	// initialiser, print size and contents
	DoubleSubscriptedArray chessBoard3(chessBoard1); //invokes copy constructor

	cout << "\nSize of DoubleSubscriptedArray chessBoard3 is"
		<< chessBoard3.getSize()
		<< "\nDoubleSubscriptedArray after initialisation:\n" << chessBoard3;

	//use overloaded assignment (=) operator
	cout << "\nAssigning chessBoard2 to chessBoard1:" << endl;
	chessBoard1 = chessBoard2; //note target array is bigger

	cout << "chessBoard1:\n" << chessBoard1
		<< "chessBoard2:\n" << chessBoard2;

	//use overloaded equality (==) operator
	cout << "\nEvaluating: chessBoard1 == chessBoard2" << endl;

	if (chessBoard1 == chessBoard2)
		cout << "chessBoard1 and chessBoard2 are equal" << endl;

	//use overloaded double subscript operator to create rvalue
	cout << "\nchessBoard1(1, 0) is " << chessBoard1(1, 0);

	//use overloaded double subscript operator to create lvalue
	cout << "\n\nAssigning 1000 to chessBoard(1, 0)" << endl;
	chessBoard1(1, 0) = 1000;
	cout << "chessBoard1:\n" << chessBoard1;

	//attempt to use out-of-range subscript
	try
	{
		cout << "\nAttempt to assign 1000 to chessBoard1(2, 0)" << endl;
		chessBoard1(2, 0) = 1000; //ERROR: double subscript out of range
	}
	catch (out_of_range& ex) {
		cout << "An exception occurred: " << ex.what() << endl;
	}
}

#endif