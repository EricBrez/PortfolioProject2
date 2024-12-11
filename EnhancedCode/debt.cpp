#include "debt.h"
#include <iostream>
#include <cctype>
#include <stdexcept>
#include<iomanip>

using namespace std;

debt::debt() { //Default constructor
	initAmount = 0.0;
	interestRate = 0.0;
	minPayment = 0.0;
	additionalPayment = 0.0;
	minPaymentPercent = 0.0;
}

void debt::SetInitAmount(double amount) { //Set initial amount
	initAmount = amount;
}

void debt::setAPR(double apr) { //Set interest rate
	interestRate = apr;
}

double debt::setPayment(double balance, double additionalPayment) {
	double Payment = balance * (minPaymentPercent / 100); //Calculate minimum payment

	if (Payment < 25.0) {
		Payment = 25.0;
	}

	Payment = Payment + additionalPayment;

	if (balance < Payment) { //final payment
		Payment = balance;
	}
	return Payment;
}

void debt::setAdditionalPayment(double additionalpayment) {
	additionalPayment = additionalpayment;
}

void debt::setMinPaymentPercent(double percent) {
	minPaymentPercent = percent;
}

void debt::printTableMinPaymentOnly() {
	double openingDebt = initAmount;
	double currBalance;
	double accruedInterest;
	double minimumPayment;
	double balanceAfterInterest;
	int month = 1;
	double totalInterest = 0.0;
	int yearsToPay;
	int monthsToPay;
	double totalPaid = 0.0;


	//Print table header
	cout << setfill(' ') << setw(67) << "Monthly Balance Paying Only Minimum Payment" << endl;
	cout << setfill('=') << setw(90) << "" << endl;
	cout << setfill(' ') << setw(10) << "Month";
	cout << setw(23) << "Month End Balance";
	cout << setw(24) << "Minimum Payment";
	cout << setw(33) << "Interest Accrued This Month" << endl;
	cout << setfill('-') << setw(90) << "" << endl;


	while (openingDebt > 0) {
		minimumPayment = setPayment(openingDebt, additionalPayment);
		currBalance = openingDebt - minimumPayment;
		accruedInterest = currBalance * ((interestRate / 100) / 12);
		balanceAfterInterest = currBalance + accruedInterest;
		openingDebt = balanceAfterInterest;
		month++;
		totalInterest += accruedInterest;
		totalPaid += minimumPayment;


		//Print table contents
		cout << setfill(' ') << setw(10) << month;
		cout << setw(23) << fixed << setprecision(2) << openingDebt;
		cout << setw(24) << fixed << setprecision(2) << minimumPayment;
		cout << setw(33) << fixed << setprecision(2) << accruedInterest << endl;
	}
	cout << setfill('=') << setw(90) << "" << endl;
	cout << setfill(' ') << setw(30) << "Total paid";
	cout << setw(30) << "Total Interest Paid";
	cout << setw(30) << "Total Time To Pay" << endl;
	yearsToPay = month / 12;
	monthsToPay = month % 12;
	cout << setw(30) << fixed << setprecision(2) << totalPaid;
	cout << setw(30) << fixed << setprecision(2) << totalInterest;
	cout << setw(11) << yearsToPay << " years and " << monthsToPay << " months" << endl;
}

void debt::printTableExtraPayment() {
	double openingDebt = initAmount;
	double currBalance;
	double accruedInterest;
	double balanceAfterInterest;
	int month = 1;
	double totalInterest = 0.0;
	int yearsToPay;
	int monthsToPay;
	double totalPaid = 0.0;
	double extraPay = additionalPayment;
	double payment;


	//Print table header
	cout << setfill(' ') << setw(67) << "Monthly Balance Paying With Extra Payments" << endl;
	cout << setfill('=') << setw(90) << "" << endl;
	cout << setfill(' ') << setw(10) << "Month";
	cout << setw(23) << "Month End Balance";
	cout << setw(24) << "Payment";
	cout << setw(33) << "Interest Accrued This Month" << endl;
	cout << setfill('-') << setw(90) << "" << endl;


	while (openingDebt > 0.0) {
		payment = setPayment(openingDebt, additionalPayment);
		currBalance = openingDebt - payment;
		accruedInterest = currBalance * ((interestRate / 100) / 12);
		balanceAfterInterest = currBalance + accruedInterest;
		openingDebt = balanceAfterInterest;
		month++;
		totalInterest += accruedInterest;
		totalPaid += payment;


		//Print table contents
		cout << setfill(' ') << setw(10) << month;
		cout << setw(23) << fixed << setprecision(2) << openingDebt;
		cout << setw(24) << fixed << setprecision(2) << payment;
		cout << setw(33) << fixed << setprecision(2) << accruedInterest << endl;
	}
	cout << setfill('=') << setw(90) << "" << endl;
	cout << setfill(' ') << setw(30) << "Total paid";
	cout << setw(30) << "Total Interest Paid";
	cout << setw(30) << "Total Time To Pay" << endl;
	yearsToPay = month / 12;
	monthsToPay = month % 12;
	cout << setw(30) << fixed << setprecision(2) << totalPaid;
	cout << setw(30) << fixed << setprecision(2) << totalInterest;
	cout << setw(11) << yearsToPay << " years and " << monthsToPay << " months" << endl;
}