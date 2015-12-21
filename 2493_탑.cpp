#include <iostream>

using namespace std;

int inputArr[500001];
int outputArr[500001];

int main()
{
	int testNum;

	cin >> testNum;

	int maxIndex = 1;


	for (int i = 1; i <= testNum; i++)
	{
		cin >> inputArr[i];
	}

	for (int i = 1; i <= testNum; i++)
	{
		for (int j = i + 1; j <= testNum; j++)
		{
			if (inputArr[i] >= inputArr[j])
			{
				outputArr[j] = i;
			}
			else
			{
				break;
			}
		}
	}

	for (int i = 1; i <= testNum; i++)
	{
		if (i != testNum)
			cout << outputArr[i] << " ";
		else
			cout << outputArr[i] << endl;
	}

	return 0;
}