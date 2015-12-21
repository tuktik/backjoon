#include <iostream>

using namespace std;

int numArr[1001];

void quick_sort(int first, int end)
{
	int pivotPoint = numArr[(first + end) / 2];

	int f = first;
	int e = end;
	while (f <= e)
	{
		while (pivotPoint > numArr[f])f++;
		while (pivotPoint < numArr[e])e--;

		if (f <= e){
			int tmp = numArr[f];
			numArr[f] = numArr[e];
			numArr[e] = tmp;

			f++;
			e--;
		}
	}
	if (first < e) quick_sort(first, e);
	if (f < end) quick_sort(f, end);
}

int main()
{
	int numCount;

	cin >> numCount;

	for (int i = 1; i <= numCount; i++)
	{
		cin >> numArr[i];
	}

	quick_sort(1, numCount);

	int sum = 0;

	for (int i = 1; i <= numCount; i++)
	{ 
		//cout << numArr[i] << endl;
		if (sum >= (numArr[i]-1))
			sum += numArr[i];
		else
			break;
	}

	cout << sum+1 << endl;
	return 0;
}