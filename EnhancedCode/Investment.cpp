#include "Investment.h"
#include<iostream>
#include<cctype>
#include<stdexcept>
#include<iomanip>
using namespace std;

Investment::Investment() { //default constructor
	initDeposit = 0.0;
	interestRate = 0.0;
	investTerm = 0;
	monthDeposit = 0.0;
}

void Investment::SetInitDeposit(double deposit) { //set initial deposit amount
	initDeposit = deposit;
}

void Investment::SetAPR(double APR) { //set interest rate
	interestRate = APR;
}

void Investment::SetTerm(int years) { //set lenght of investment
	investTerm = years;
}

void Investment::SetMonthlyDeposit(double monthlyDeposit) { // set montly contribution
	monthDeposit = monthlyDeposit;
}

void Investment::PrintTableWithDeposit() { // print table with deposit
	double openingBalance = initDeposit;
	double currOpeningBalance;
	double earnedInterest; //declare helper variables 
	double totalAfterInterest;
	double interestEarned = 0.0; //initialize year end interest to 0.0
	
	cout << setfill(' ') << setw(50) << "Yearly Balance With Monthly Deposit" << endl;
	cout << setfill('=') << setw(66) << "" << endl;
	cout << setfill(' ') << setw(10) << "Year";
	cout << setw(25) << "Year End Balance";
	cout << setw(31) << "Year End Interest Earned" << endl;
	cout << setfill('-') << setw(66) << "" << endl;
	for (int i = 1; i <= investTerm; ++i) {
		for (int j = 0; j < 12; ++j) { //iterate through each month of every year of term
			currOpeningBalance = openingBalance + monthDeposit; // adding monthly contribution
			earnedInterest = currOpeningBalance * ((interestRate / 100) / 12);  // perform calculations to determine the month end values for balance and interest
			totalAfterInterest = currOpeningBalance + earnedInterest;
			openingBalance = totalAfterInterest;
			interestEarned += earnedInterest; //add each month's interest to a running total for the year
		}
		cout << setfill(' ') << setw(10) << i;
		cout << setw(25) << fixed << setprecision(2) << totalAfterInterest;
		cout << setw(31) << fixed << setprecision(2) << interestEarned << endl; //print each formatted row to display data
		interestEarned = 0.0; //reset yearly interest for the next year
	}
}

void Investment::PrintTableWithNoDeposit() {
	double openingBalance = initDeposit;
	double currOpeningBalance;
	double earnedInterest;
	double totalAfterInterest;
	double interestEarned = 0.0;

	cout << setfill(' ') << setw(53) << "Yearly Balance With No Monthly Deposit" << endl;
	cout << setfill('=') << setw(66) << "" << endl;
	cout << setfill(' ') << setw(10) << "Year";
	cout << setw(25) << "Year End Balance";
	cout << setw(31) << "Year End Interest Earned" << endl;
	cout << setfill('-') << setw(66) << "" << endl;
	for (int i = 1; i <= investTerm; ++i) { //iterate through each month of each year and perform calculations
		for (int j = 0; j < 12; ++j) {
			currOpeningBalance = openingBalance; //ensuring that monthly contribution is not added
			earnedInterest = currOpeningBalance * ((interestRate / 100) / 12);
			totalAfterInterest = currOpeningBalance + earnedInterest;
			openingBalance = totalAfterInterest;
			interestEarned += earnedInterest; //add monthly interest to running total for year
		}
		cout << setfill(' ') << setw(10) << i;
		cout << setw(25) << fixed << setprecision(2) << totalAfterInterest;
		cout << setw(31) << fixed << setprecision(2) << interestEarned << endl;
		interestEarned = 0.0; //reset yearly interest for next year
	}
}