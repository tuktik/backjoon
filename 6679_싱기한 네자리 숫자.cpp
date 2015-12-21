#include <iostream>

using namespace std;

int getTenVal(int num)
{
	int sum = 0;

	while (num != 0)
	{
		sum += num % 10;
		num = num / 10;
	}

	return sum;
}

int getSixteenVal(int num)
{
	int sum = 0;

	while (num != 0)
	{
		sum += num % 16;
		num = num / 16;
	}

	return sum;
}

int getTwenteenVal(int num)
{
	int sum = 0;

	while (num != 0)
	{
		sum += num % 12;
		num = num / 12;
	}

	return sum;
}
int main()
{

	for (int i = 1000; i <= 9999; i++)
	{
		if (getTenVal(i) == getTwenteenVal(i) && getTenVal(i) == getSixteenVal(i))
		{
			cout << i << endl;
		}
	}

	return 0;
}