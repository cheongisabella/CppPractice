//#ifdef TEST_CH19EX10
#include "Account.h"
#include <stdexcept>

using namespace std;

Account::Account(double initialBalance) {
	if (initialBalance >= 0)
		setBalance(initialBalance);
	else {
		setBalance(0.0);
		throw invalid_argument("Initial balance invalid, should be more than 0.0\n");
	}	
}

void Account::setBalance(double amt) {
	balance = amt;
}

double Account::getBalance() const {
	return balance;
}

void Account::credit(double amtToAdd) {
	setBalance(getBalance() + amtToAdd);
}

bool Account::debit(double amtToWithdraw) {
	if (getBalance() >= amtToWithdraw) {
		setBalance(getBalance() - amtToWithdraw);
		return true;
	}
	else {
		throw invalid_argument("Debit amount exceeded account balance.");
	}
}
//#endif