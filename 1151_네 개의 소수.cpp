#include <iostream>

using namespace std;

int eratosArr[1000001];

int main()
{
	int number;

	cin >> number;

	for (int i = 2; i <= number; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (eratosArr[j] == 1 && eratosArr[i] % eratosArr[j] ==0)
			{
				eratosArr[j]
			}
		}
	}


	return 0;
}