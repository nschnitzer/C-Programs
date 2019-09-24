#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double height, radius;
	const double PI = 3.14159;
	
	cout << "Enter the height of the cylinder";
	cin >> height;
	
	cout << "Enter the radius of the cylinder";
	cin >> radius;
	
	cout << fixed << showpoint << setprecision(2);
	
	cout << "Volume of the cylinder = " << PI * pow(radius,2.0)*height << endl;
	
	cout << "Surface Area: " << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0) << endl;
	
	return 0; 
}