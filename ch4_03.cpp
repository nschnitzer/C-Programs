#include <iostream>
using namespace std;

//65 = A

int main()
{
	cout << "Please enter a number between 0 and 35" << endl;
	int num;
	cin >> num;
	if (num < 9)
	{
		cout << num << endl;
		return 0;
	}
	
	num = num + 55;
	cout << static_cast<char>(num) << endl;
	return 0;
}