#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "Please enter the account information" << endl;
	int accNum, numMins;
	char serviceType;
	double charge;
	cin >> accNum >> serviceType >> numMins;
	
	if (serviceType == 'r' || serviceType == 'R')
	{
		charge = 10.00;
		if (numMins > 50)
		{
			charge = charge + (numMins-50)*.2;
		}
	}
	else
	{
		charge = 25.00;
		cout << "Please enter the amount of minutes used during the day" << endl;
		int dayMins, nightMins;
		cin >> dayMins;
		nightMins = numMins - dayMins;
		if (dayMins > 75)
		{
			charge = charge + .1*(dayMins-75);
		}
		if (nightMins > 100)
		{
			charge = charge + .05*(nightMins-100);
		}
	}
	
	cout << "Charge for account " << accNum << " is $" << charge << endl;
	return 0;
}