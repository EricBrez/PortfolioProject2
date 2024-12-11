#ifndef DEBT_H
#define DEBT_H

class debt {
public:
	debt();
	void SetInitAmount(double amount);
	void setAPR(double apr);
	double setPayment(double monthlyPayment, double extraPaid);
	void printTableMinPaymentOnly();
	void printTableExtraPayment();
	void setAdditionalPayment(double additionalPayment);
	void setMinPaymentPercent(double percent);
private:
	double interestRate;
	double initAmount;
	double minPayment;
	double additionalPayment;
	double minPaymentPercent;
};

#endif
