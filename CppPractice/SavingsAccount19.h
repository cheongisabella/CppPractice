#pragma once
#ifdef TEST_CH19EX10

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class SavingsAccount : public Account {
public:
	SavingsAccount(double=0.0, double=0.0);
	double getInterest() const;
	double calculateInterest() const;
private:
	double interestRate;
};



#endif
#endif