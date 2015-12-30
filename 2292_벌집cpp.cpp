#include <iostream>

using namespace std;

int main()
{
	int sum = 1;
	
	int input;

	cin >> input;
	
	int i;
	
	for (i = 1; input > sum; i++)
	{
		sum += 6 * i;
	}
	
	cout << i << endl;



	return 0;
}