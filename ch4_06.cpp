#include <iostream>
using namespace std;

int main()
{
	int s1, s2, s3;
	cout << "Please enter the sides of the triangle (Hypotenuse last)" << endl;
	cin >> s1 >> s2 >> s3;
	
	if ((s1 * s1 + s2 * s2) == s3 * s3)
	{
		cout << "It is a right triangle" << endl;
	}
	else
	{
		cout << s1 * s1 + s2 * s2
		cout << "It is not a right triangle" << endl;
	}
	return 0;
}