//#ifdef TEST_CH19EX10

#include "CheckingAccount.h"
#include <stdexcept>
#include <iostream>

using namespace std;

CheckingAccount::CheckingAccount(double initialBalance, double initialFee)
	: Account(initialBalance)
{
	if (initialFee >= 0)
		setFee(initialFee);
	else {
		setFee(0.0);
		throw invalid_argument("Initial fee invalid, should be more than 0.0\n");
	}
}

void CheckingAccount::setFee(double feeAmt) {
	fee = feeAmt;
}

double CheckingAccount::getFee() const {
	return fee;
}

void CheckingAccount::credit(double amtToAdd) {
	Account::credit(amtToAdd);
	setBalance(getBalance() - getFee());
}

bool CheckingAccount::debit(double amtToWithdraw) {
	try {
		if (Account::debit(amtToWithdraw)) {
			setBalance(getBalance() - getFee());
		}
		return true;
	}
	catch (invalid_argument& ex) {
		cout << "An exception occurred: " << ex.what() << endl;
	}
}

//#endif