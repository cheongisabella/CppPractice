#ifdef TEST_CH19EX10
#include "SavingsAccount19.h"
#include "CheckingAccount.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	SavingsAccount savings1(5400.0, 3.2);
	SavingsAccount savings2;

	cout << fixed << setprecision(2);

	cout << "Balance in savings1 is " << savings1.getBalance()
		<< "\nInterest rate in savings1 is " << savings1.getInterest() << endl;

	cout << "Balance in savings2 is " << savings2.getBalance()
		<< "\nInterest rate in savings2 is " << savings2.getInterest() << endl;

	cout << "savings1 earns interest of " << savings1.calculateInterest();
	savings1.credit(savings1.calculateInterest());
	cout << "\nBalance in savings1 after interest is " << savings1.getBalance() << endl;

	CheckingAccount checking1(6500.23, 6.51);
	
	try {
		cout << "Creating checking2 with negative balance" << endl;
		CheckingAccount checking2(-5, 0);
	}
	catch (invalid_argument &ex) {
		cout << "An exception occurred: " << ex.what() << endl;
	}

	cout << "Balance in checking1 is " << checking1.getBalance()
		<< "\nFee charged per transaction for checking1 is " << checking1.getFee() << endl;

	cout << "Trying to withdraw 7000 from checking1: " << endl;
	checking1.debit(7000);

	checking1.debit(1000);
	
	cout << "After withdrawing 1000 from checking1, balance is "
		<< checking1.getBalance() << endl;

	checking1.credit(500);
	cout << "After adding 500 to checking 1, balance is "
		<< checking1.getBalance() << endl;


}

#endif