#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ofstream outData;
	outData.open("output.txt");
	
	const double INCOME_TAX_RATE = .15;
	const double STATE_TAX_RATE = .035;
	const double SS_TAX_RATE = .0575;
	const double MEDICARE_TAX_RATE = .0275;
	const double PENSION_DEDUCT_RATE = .05;
	const double HEALTH_INSURANCE = 75.00;
	
	string firstName, lastName;
	double grossAmount, fedTax, stateTax, ssTax, medicareTax, pension, netPay;
	outData << "Please enter the employee's name followed by their pay" << endl;
	cin >> firstName >> lastName >> grossAmount;
	
	fedTax = grossAmount * INCOME_TAX_RATE;
	stateTax = grossAmount * STATE_TAX_RATE;
	ssTax = grossAmount * SS_TAX_RATE;
	medicareTax = grossAmount * MEDICARE_TAX_RATE;
	pension = grossAmount * PENSION_DEDUCT_RATE;
	netPay = grossAmount - fedTax - stateTax - ssTax - medicareTax - pension - HEALTH_INSURANCE;
	
	outData << endl;
    outData << fixed << showpoint;
	outData << firstName << " " << lastName << ":" << endl;
	outData << right;
	outData << setfill(' ');
	outData << "Gross Amount: ........ $" << setprecision(2) << setw(7) << grossAmount << endl;;
	outData << "Federal Tax: ........ $" << setprecision(2) << setw(7) << fedTax << endl;
	outData << "State Tax: ......... $" << setprecision(2) << setw(7) << stateTax << endl;
	outData << "Social Security: ......... $" << setprecision(2) << setw(7) << ssTax << endl;
	outData << "Medicare/Medicade Tax: ......... $" << setprecision(2) << setw(7) << medicareTax << endl;
	outData << "Pension: ......... $" << setprecision(2) << setw(7) << pension << endl;
	outData << "Health Insurance: ......... $" << setprecision(2) << setw(7) << HEALTH_INSURANCE << endl;
	outData << "Net Pay: ......... $" << setprecision(2) << setw(7) << netPay << endl;
	
	return 0;
}