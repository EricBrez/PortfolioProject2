#include<iostream>
#include<cctype>
#include<stdexcept>
#include<iomanip>
#include <string>
#include "Investment.h"
#include "debt.h"

using namespace std;

int main() {
	string userChoice = "initValue";

	cout << "Welcome to the financial calculator." << endl << endl;

	while (userChoice != "q") {
		try {
			cout << "Would you like to calculate your returns on an investment or the length of time to pay off a debt?" << endl;
			cout << "[1] - Investment" << endl;
			cout << "[2] - Debt" << endl;
			cout << "[q] - quit" << endl;
			cin >> userChoice;
			if (userChoice == "q") {
				break;
			}
			else if (userChoice == "1") {
				double initAmount;
				double interestRate;
				int investTerm;
				double monthlyDeposit;
				Investment newInvestment;
				cout << "First a few questions about your investment:" << endl << endl;

				//Get initial amount
				cout << "How much are you going to initially invest?" << endl;
				if (cin >> initAmount) {
					cout << "Initial Deposit: $" << initAmount << endl << endl;
					newInvestment.SetInitDeposit(initAmount);
				}
				else { throw runtime_error("Invalid initial amount"); }

				//Get interest rate
				cout << "What interest rate is your investment at?" << endl;
				if (cin >> interestRate) {
					cout << "Your interest rate: " << interestRate << "%" << endl << endl;
					newInvestment.SetAPR(interestRate);
				}
				else { throw runtime_error("Invalid interest rate"); }

				//Get investment term
				cout << "How many years are you going to invest for?" << endl;
				if (cin >> investTerm) {
					cout << "You are investing for " << investTerm << " years." << endl << endl;
					newInvestment.SetTerm(investTerm);
				}
				else { throw runtime_error("Invalid investment length"); }

				//Get monthly deposit
				cout << "If you are planning on deposting monthly, enter the amount here, otherwise, enter '0'" << endl;
				if (cin >> monthlyDeposit) {
					cout << "You plan on depositing $" << monthlyDeposit << " every month" << endl << endl;
					newInvestment.SetMonthlyDeposit(monthlyDeposit);
				}
				else { throw runtime_error("Invalid monthly deposit"); }

				cout << "Press enter to see your results" << endl;

				cin.ignore();
				cin.get();

				cout << endl << endl;

				//Print appropriate table
				if (monthlyDeposit == 0.0) {
					newInvestment.PrintTableWithNoDeposit();
				}
				else {
					newInvestment.PrintTableWithDeposit();
				}
			}
			else if (userChoice == "2") {
				double initAmount;
				double interestRate;
				double additionalPayments;
				double minPaymentPercentage;
				debt newDebt;

				cout << "First some questions about the debt:" << endl << endl;

				//Get Initial amount
				cout << "How much is the debt?" << endl;
				if (cin >> initAmount) {
					cout << "The debt is $" << initAmount << "." << endl << endl;
					newDebt.SetInitAmount(initAmount);
				}
				else {throw runtime_error("Invalid initial amount"); }

				//Get interest rate
				cout << "What is your interest rate?" << endl;
				if (cin >> interestRate) {
					cout << "Your interest rate is %" << interestRate << "." << endl << endl;
					newDebt.setAPR(interestRate);
				}
				else { throw runtime_error("Invalid interest rate"); }

				//Get additional payments
				cout << "How much are you planning to pay in addition to the minimum payment each month?" << endl;
				cout << "If none, enter 0" << endl;
				if (cin >> additionalPayments) {
					cout << "You plan on paying $" << additionalPayments << " extra each month" << endl << endl;
					newDebt.setAdditionalPayment(additionalPayments);
				}
				else {throw runtime_error("Invalid payment amount"); }

				//Get minimum payment percentage
				cout << "What is your minimum payment percentage?" << endl;
				if (cin >> minPaymentPercentage) {
					cout << "Your minimum payment percentage is %" << minPaymentPercentage << endl << endl;
					newDebt.setMinPaymentPercent(minPaymentPercentage);
				}
				else {throw runtime_error("Invalid minimum payment percentage"); }

				cout << "Press enter to see your results";
				cin.ignore();
				cin.get();

				//Print Table
				if (additionalPayments == 0.0) {
					newDebt.printTableMinPaymentOnly();
				}
				else {
					newDebt.printTableExtraPayment();
				}
				
			}
		}
		catch (runtime_error& excpt) {
			string exitProgram;
			cout << "ERROR: " << excpt.what() << endl;
			cout << "Please ensure you are only entering numerical values." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Are you trying to exit the financial calculator?" << endl;
			cout << "[1] - Yes" << endl << "[2] - No" << endl;
			cin >> exitProgram;
			while (1) {
				if (exitProgram == "1" || exitProgram == "2") {
					break;
				}
				else {
					cout << "I'm sorry, I didn't quite get that." << endl;
					cout << "Are you trying to exit the financial calculator?" << endl;
					cout << "[1] - Yes" << endl << "[2] - No" << endl;
					cin >> exitProgram;
				}
			}
			if (exitProgram == "1") {
				break;
			}
			else {
				continue;
			}
		}

	}
	
	
	return 0;
}