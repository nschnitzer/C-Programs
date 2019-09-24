#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	
	ifstream.open("inData.txt");
	ofstream.open("outData.txt");
	
	double length, width, radius, balance, interestRate;
	string firstName, lastName;
	int age;
	char letter;
	
	inFile >> length >> width;
	inFile.ignore('\n');
	inFile >> radius;
	inFile >> firstName >> lastName >> age;
	inFile >> balance >> interestRate >> letter;
	
	double area = length * width;
	double perimeter = 2 * length + 2 * width;
	
	outFile << "Rectangle" << endl;
	outFile << "Length = " << length << ", width = " << width << ", area = " << area << ", perimeter = " << perimeter << endl;
	
	outFile << endl;
	
	outFile << "Circle: " << endl;
	area = 2 * 3.1416 * radius;
	double circumfrence = 2 * radius;
	outFile << "Radius = " << radius << ", area = " << area << ", circumfrence = " << circumfrence << endl;
	
	outFile << endl;
	
	outFile << "Name: " << firstName << " " << lastName << ", age: " << age << endl;
	outFile << "Beginning Balance = $" << balance << ", interest rate = " << interestRate << endl;
	balance = balance * interestRate;
	outFile << "Balance at the end of the month = " << balance << endl;
	return 0;
}