#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>

#include "Account.h"
#include "SavingsAccount19.h"
#include "CheckingAccount.h"

using namespace std;

int main() {

	// set floating point output formatting
	cout << fixed << setprecision(2);

	// create derived-class objects
	SavingsAccount savingsAccount1(5000, 2.2);
	CheckingAccount checkingAccount(1234, 4.68);
	SavingsAccount savingsAccount2(10000, 1.8);

	cout << "Accounts processed individually using static binding:\n\n";

	// output each Account's balance and information using static binding
	cout << "Balance of savingsAccount1 is " << savingsAccount1.getBalance()
		<< "\nInterest of savingsAccount 1 is " << savingsAccount1.getInterest() << "\n\n";

	cout << "Balance of checkingAccount is " << checkingAccount.getBalance()
		<< "\nFee charged per transaction of checkingAccount is " << checkingAccount.getFee() << "\n\n";

	cout << "Balance of savingsAccount2 is " << savingsAccount2.getBalance()
		<< "\nInterest of savingsAccount2 is " << savingsAccount2.getInterest() << "\n\n";

	// create vector of three base-class Account pointers
	vector<Account*> accounts(3);

	//	initialise vector with pointers to Accounts
	accounts[0] = &savingsAccount1; // accounts[0] = new SavingsAccount(5000, 2.2); 
	accounts[1] = &checkingAccount;
	accounts[2] = &savingsAccount2;

	cout << "Accounts processed polymorphically using dynamic binding:\n\n";

	for (Account* accountPtr : accounts) {
		double withdrawAmount, depositAmount;
		
		cout << "How much would you like to withdraw?" << endl;
		cin >> withdrawAmount;

		if (accountPtr->debit(withdrawAmount)) {
			cout << "Balance of account after withdrawal is " << accountPtr->getBalance() << "\n\n";
		}

		cout << "How much would you like to deposit?" << endl;
		cin >> depositAmount;

		accountPtr->credit(depositAmount);

		cout << "Balance of account after deposit is " << accountPtr->getBalance() << "\n\n";

		SavingsAccount* derivedSavingsPtr = dynamic_cast<SavingsAccount*>(accountPtr);

		if (derivedSavingsPtr != nullptr) { // accountPtr points to SavingsAccount
			cout << "Interest earned by SavingsAccount is " << derivedSavingsPtr->calculateInterest() << endl;
			derivedSavingsPtr->credit(derivedSavingsPtr->calculateInterest());
			cout << "Balance of SavingsAccount after interest is " << derivedSavingsPtr->getBalance() << "\n\n";
		}
	
	}

	/*
	// release dynamically allocated objects pointed to by vector's elements (using new)
	for (const Account* accountPtr : accounts) {
		cout << "deleting object of " << typeid(*accountPtr).name() << endl;
		delete accountPtr;
	}
	*/

}