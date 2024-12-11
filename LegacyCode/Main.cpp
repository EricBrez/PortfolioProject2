#include<iostream>
#include<cctype>
#include<stdexcept>
#include<iomanip>
#include "Investment.h"
#include <string>
using namespace std;

int main() {
	double initDeposit;
	double monthlyDeposit;
	double yearlyInterest;
	int numYears;
	char doAnother;
	Investment newInvestment; //new investment object
	bool isValid = false; //initialization necessary to begin input collection and validation

	while (!isValid) { //iterates through input collection until all inputs are validated
		try {
			cout << "************************************" << endl;
			cout << "************ Data Input ************" << endl;
			cout << "Initial Investment Amount: $";
			if (cin >> initDeposit) {
				cout << "Monthly Deposit: $";
			}
			else {
				throw(runtime_error("Invalid input")); //each if-else statement validates user input and throws a runtime error that allows for correction if input is not a double or cannot be converted to a double
			}
			if (cin >> monthlyDeposit) {
				cout << "Annual Interest: %";
			}
			else {
				throw(runtime_error("Invalid input"));
			}
			if (cin >> yearlyInterest) {
				cout << "Number of Years: ";
			}
			else {
				throw(runtime_error("Invalid input"));
			}
			if (cin >> numYears) {
				cout << "Press Enter to continue. . .";
			}
			else {
				throw(runtime_error("Invalid input"));
			}
			cin.ignore(); // allows for user to press enter to continue with next steps
			cin.get();

			newInvestment.SetInitDeposit(initDeposit); // set valid inputs
			newInvestment.SetAPR(yearlyInterest);
			newInvestment.SetTerm(numYears);
			newInvestment.SetMonthlyDeposit(monthlyDeposit);

			cout << endl;
			cout << endl;

			
			newInvestment.PrintTableWithNoDeposit(); //print table without monthly deposit
			
			cout << endl;
			cout << endl;

			newInvestment.PrintTableWithDeposit(); // print table with monthly deposit

			cout << endl;
			cout << endl;
			cout << "Would you like to do another? \"y\" or \"n\": " ;
			cin >> doAnother;
			doAnother = tolower(doAnother); //get and validate user input to do another investment table or to quit or repeats doAnother code if invalid input
			while (doAnother != 'y') {
				if (doAnother == 'n') {
					return 0;
				}
				else {
					cout << endl;
					cout << "Please enter either \"y\" or \"n\"" << endl;
					cout << "Would you like to do another? ";
					cin >> doAnother;
					doAnother = tolower(doAnother);
				}
			}

			cout << endl;
			cout << endl;
		}
		catch (runtime_error excpt) {
			string exitProgram;
			cout << "ERROR: " << excpt.what();
			cout << "Please ensure you are only entering numerical values." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Are you trying to exit the investment calculator?" << endl;
			cout << "[1] - Yes" << endl << "[2] - No" << endl;
			cin >> exitProgram;
			while (1) {
				if (exitProgram == "1" || exitProgram == "2") {
					break;
				}
				else {
					cout << "I'm sorry, I didn't quite get that." << endl;
					cout << "Are you trying to exit the investment calculator?" << endl;
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