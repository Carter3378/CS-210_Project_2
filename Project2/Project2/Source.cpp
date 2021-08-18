#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;


void DefaultDisplay() { //Displays a preview of info required from user
	cout << "*****************************************" << endl;
	cout << "****************Data Input***************" << endl;
	cout << "Initial investment amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	system("PAUSE");
}
void InputDisplay(double &initialInvestment,double &monthlyDeposit, double &annualInterst,int &numYears) { //Displays and takes in users data
	label:
	try {// try's user input
		cout << "*****************************************" << endl;
		cout << "****************Data Input***************" << endl;
		cout << "Initial investment amount: $";
		cin >> initialInvestment;
		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << "Annual Interest: %";
		cin >> annualInterst;
		cout << "Number of years: ";
		cin >> numYears;
		system("PAUSE");
		
		if (initialInvestment < 0 || monthlyDeposit < 0 || annualInterst < 0 || numYears < 0) {//validates user input
			throw runtime_error("Invalid entry of negative integer");
	}
	}
	
	catch (runtime_error& excpt) {//catches the runtime error and throws the user back to the beggining
		cout << excpt.what() << endl;
		cout << "All inputs must be positive" << endl;
		goto label;
	}
}
void PrintWithoutDeposits(double numYears,double interestAmount, double total, double annualInterest) {//function prints results from data without the deposit factor
	cout << "  Balance and Interest Without Additional Monthly Deposits  " << endl;
	cout << "============================================================" << endl;
	cout << "  Year        Year End Balance      Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < numYears; i++) {//for loop to iterate through number of years while accumulating interest
		interestAmount = total * (annualInterest / 100);
		total += interestAmount;
		cout << i + 1 << "		     " << fixed << setprecision(2) << total << "		   " << interestAmount << endl;
	}
}
void PrintWithDeposits(double numYears, double totalInterest, double interestAmount, double total, double monthlyDeposit, double annualInterest) {//function prints results from data including the deposit factor
	cout << endl;
	cout << "    Balance and Interest With Additional Monthly Deposits   " << endl;
	cout << "============================================================" << endl;
	cout << "  Year        Year End Balance      Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------" << endl;


	for (int i = 0; i < numYears; i++) {//iterates through years while clearing totalinterest for the next year
		totalInterest = 0;
		for (int j = 0; j < 12; j++) {//iterates through months of the year to add recurring deposits while printing results

			interestAmount = (total + monthlyDeposit) * (annualInterest / 100 / 12);
			totalInterest += interestAmount;
			total = total + monthlyDeposit + interestAmount;
		}
		cout << i + 1 << "		   " << fixed << setprecision(2) << total << "		    " << totalInterest << endl;

	}
}
int main() {//declare variables
	double initialInvestment = 0.0;
	double annualInterest = 0.0;
	double monthlyDeposit = 0.0;
	int numMonths = 0;
	int numYears = 0;
	double total = 0.0;
	double interestAmount = 0.0;
	double totalInterest = 0.0;

	DefaultDisplay();//print default unfilled display
	
	InputDisplay(initialInvestment, monthlyDeposit, annualInterest, numYears);//calls display for input
	
	numMonths = numYears * 12;//initialize months
	total = initialInvestment;//initialize total

	PrintWithoutDeposits(numYears, interestAmount,total, annualInterest);//calls output function

	total = initialInvestment;//resets total

	PrintWithDeposits(numYears, totalInterest, interestAmount,total,monthlyDeposit, annualInterest);//calls output function

	system("PAUSE");//pauses system so it wont immediatly terminate
	return 0;
}