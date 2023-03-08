#pragma once
//#ifdef TEST_CH19EX10
#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class CheckingAccount : public Account {
public:
	CheckingAccount(double = 0.0, double = 0.0);
	void setFee(double);
	double getFee() const;

	virtual void credit(double) override;
	virtual bool debit(double) override;
private:
	double fee;
};

#endif
//#endif
