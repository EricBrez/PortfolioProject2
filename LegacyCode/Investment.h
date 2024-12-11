#ifndef INVESTMENT_H
#define INVESTMENT_H


class Investment {
public: // Declare methods for use in main()
	void SetInitDeposit(double deposit);
	Investment();
	void SetAPR(double APR);
	void SetTerm(int years);
	void SetMonthlyDeposit(double monthlyDeposit);
	void PrintTableWithDeposit();
	void PrintTableWithNoDeposit();
private: //declare variables for wide use in investment()
	double interestRate;
	double initDeposit;
	int investTerm;
	double monthDeposit;
};

#endif