#ifdef TEST_CH17EX20
#ifndef SAVINGS_H
#define SAVINGS_H

class SavingsAccount {
public:
	explicit SavingsAccount(float = 0.0); //default constructor
	void calculateMonthlyInterest();
	static void modifyInterestRate(float);
	static float getInterest();
	float getBalance() const;
	void printAccount() const;
private:
	static float annualInterestRate;
	float savingsBalance;
};

#endif
#endif