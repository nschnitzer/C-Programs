#include <iostream>
using namespace std;

int main()
{
	cout << "Please enter 3 numbers" << endl;
	double a,b,c;
	cin >> a >> b >> c;
	
	if (a < b)
	{
		if (b < c)
		{
			cout << a << " " << b << " " << c << endl;
			return 0;
		}
		else if (c < a)
		{
			cout << c << " " << a << " " << b << endl;
			return 0;
		}
		else
		{
			cout << a << " " << c << " " << b << endl;
			return 0;
		}
	}
	else if (b < c)
	{
		if (a < c)
		{
			cout << b << " " << a << " " << c << endl;
			return 0;
		}
		else
		{
			cout << b << " " << c << " " << a << endl;
			return 0;
		}
	}
	else
	{
		cout << c << " " << b << " " << a << endl;
		return 0;
	}
}