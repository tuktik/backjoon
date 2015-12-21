#include <iostream>

using namespace std;

int main()
{
	int n;
	int sum = 1;
	int input;

	cin >> n;
	
	for (int i = n; i > 0; i--)
	{
		//sum = 1;
		cin >> input;

		sum -= 1;
		sum += input;
	}


	cout << sum << endl;

	return 0;
}