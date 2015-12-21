#include <iostream>

using namespace std;

bool eratosArr[300000];

void eratos()
{
	eratosArr[1] = 0;
	for (int i = 2; i < 300000; i++)
		eratosArr[i] = 1;

	for (int i = 2; i*i < 300000; i++)
	{
		if (eratosArr[i] == true)
		{
			for (int j = i*i; j < 300000; j += i)
			{
				eratosArr[j] = 0;
			}
		}
	}
}

int main()
{
	int num;
	int count = 0;
	eratos();

	cin >> num;
	while (num!=0)
	{
		count = 0;

		for (int i = num+1; i <=2*num; i++)
		{
			if (eratosArr[i] == 1)
				count++;
		}
		cout << count << endl;
		cin >> num;
	}

	return 0;
}