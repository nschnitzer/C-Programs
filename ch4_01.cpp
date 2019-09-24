#include <iostream>
using namespace std;

int main()
{
	cout << "Please enter a number" << endl;
	double num;
	cin >> num;
	if (num == 0)
	{
		cout << "The number is 0" << endl;
		return 0;
	}
	else if (num > 0)
	{
		cout << "The number is greater than 0" << endl;
		return 0;
	}
	else
	{
		cout << "The number is less than 0" << endl;
		return 0;
	}
}