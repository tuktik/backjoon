#include <iostream>

using namespace std;

int inputArr[11];
int sumArr[11];

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
	if (f < end) quick_sort(f, end);
}

int main()
{
	int inputNum;

	cin >> inputNum;


	for (int i = 0; i < inputNum; i++)
	{
		cin >> inputArr[i];
	}
	
	quick_sort(0, inputNum - 1);

	int f = 0;
	int e = inputNum - 1;

	int sum = 0;

	while (f <e)
	{
		int tmp = inputArr[f] - inputArr[e];
		//cout << inputArr[f] << " " << inputArr[e] << endl;
		if (e-f> 2)
		{
			if (tmp > 0)
			{
				sum += tmp * 2;
			}
			else
				sum -= tmp * 2;
			f++;
			e--;
		}
		else
		{
			if (tmp > 0)
			{
				sum += tmp ;
			}
			else
				sum -= tmp;
		
			int first = inputArr[f + 1] - inputArr[e] > 0? inputArr[f + 1] - inputArr[e]: -(inputArr[f + 1] - inputArr[e]);
			int second = inputArr[f] - inputArr[e-1] > 0? inputArr[f] - inputArr[e-1]: -(inputArr[f] - inputArr[e-1]);
			if (first > second)
				f++;
			else
				e--;
		}
	}

	cout << sum << endl;

	return 0;
}