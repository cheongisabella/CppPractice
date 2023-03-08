//#ifdef TEST_CH19EX10

#include "SavingsAccount19.h"

SavingsAccount::SavingsAccount(double initialBalance, double initialInterest) 
	: Account(initialBalance), interestRate(initialInterest)
{}

double SavingsAccount::getInterest() const {
	return interestRate;
};

double SavingsAccount::calculateInterest() const {
	return getInterest() / 100 * getBalance();
}

//#endif