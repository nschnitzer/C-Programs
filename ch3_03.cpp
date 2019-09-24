#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double weight;
	cout << "Please enter the person's weight in kg" << endl;
	cin >> weight;
	weight = weight * 2.2;
	cout << fixed << showpoint;
	cout << "Your weight in lbs: ";
	cout << setprecision(2) << weight << end;
	return 0;
}
