#ifdef TEST_CH17EX20
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

//define and initialise static data member
float SavingsAccount::annualInterestRate = 0.0;

//define static member function 
void SavingsAccount::modifyInterestRate(float newRate) {
	annualInterestRate = newRate;
}

float SavingsAccount::getInterest() {
	return annualInterestRate;
}

//constructor initialises non-static data members
SavingsAccount::SavingsAccount(float balance)
: savingsBalance(balance) {}

void SavingsAccount::calculateMonthlyInterest() {
	float monthlyInterest = savingsBalance * annualInterestRate / 100 / 12;
	savingsBalance += monthlyInterest;
}

float SavingsAccount::getBalance() const {
	return savingsBalance;
}

void SavingsAccount::printAccount() const {
	std::cout << "Savings balance: $" << std::fixed << std::setprecision(2) << getBalance() 
		<< ", annual interest rate: " << getInterest() << "%" << std::endl;
}

#endif


