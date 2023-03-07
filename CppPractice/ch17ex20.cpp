#ifdef TEST_CH17EX20
#include "SavingsAccount.h"
#include <iostream>

int main() {

	std::cout << "Before creating any objects of class, static variable annualInterestRate = "
		<< SavingsAccount::getInterest() << std::endl;

	SavingsAccount saver0;
	saver0.printAccount();

	SavingsAccount saver1(2000.00);
	SavingsAccount saver2(3000.00);
	saver1.printAccount();
	saver2.printAccount();

	saver1.modifyInterestRate(3);
	saver1.printAccount();
	saver2.printAccount();

	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	saver1.printAccount();
	saver2.printAccount();

	saver2.modifyInterestRate(4);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	saver1.printAccount();
	saver2.printAccount();
}

#endif
