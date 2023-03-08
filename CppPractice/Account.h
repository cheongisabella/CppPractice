#pragma once
//#ifdef TEST_CH19EX10
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
	Account(double = 0.0);
	void setBalance(double);
	double getBalance() const;

	virtual void credit(double); 
	virtual bool debit(double); 
private:
	double balance;
};

#endif
//#endif