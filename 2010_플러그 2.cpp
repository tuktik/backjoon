#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int multSum;
	int mult;

	for (int i = 0; i < n; i++)
	{
		cin >> mult;
		if (i == 0)
		{
			multSum = mult;
		}
		else
		{
			multSum -= 1;
			multSum += mult;
		}
	}

	cout << multSum << endl;
	return 0;
}