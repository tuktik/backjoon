#include <iostream>

using namespace std;

int inputArr[51];
int dpArr[51];

void quick_sort(int first, int end)
{
	int pivot = inputArr[(first + end) / 2];

	int f = first;
	int e = end;

	while (f <= e)
	{
		while (inputArr[f] < pivot) f++;
		while (pivot < inputArr[e]) e--;
		
		if (f <= e)
		{
			int tmp = inputArr[f];
			inputArr[f] = inputArr[e];
			inputArr[e] = tmp;
			f++;
			e--;
		}
	}

	if (first < e) quick_sort(first, e);
	if (f< end) quick_sort(f, end);
}

int main()
{
	int testNum;
	int sum = 0;

	cin >> testNum;

	for (int a = 0; a < testNum; a++)
	{
		sum = 0;

		int inputNum;

		cin >> inputNum;

		for (int i = 0; i < inputNum; i++)
		{
			cin >> inputArr[i];

			int j = 0;
			for (j = 1; j <= i; j++)
			{
				if (inputArr[j] >= inputArr[i])
					break;
			}

			sum += (j * 2 - 1);

			quick_sort(0, i);
		}
		cout << sum << endl;
	}

	return 0;
}