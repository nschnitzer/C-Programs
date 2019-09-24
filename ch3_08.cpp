#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inFile;
	ofstream outData;
	
	inFile.open("input.txt");
	outData.open("Ch3_Ex8Output.dat");
	
	string firstName, lastName;
	double currentSalary, updatedSalary, raisePercent;
	
	inFile >> firstName >> lastName >> currentSalary >> raisePercent;
	updatedSalary = currentSalary * raisePercent;
	
	outdata << fixed << showpoint;
	outData << firstName << " " << lastName << ": " << setprecision(2) << updatedSalary << endl;
	return 0;
}