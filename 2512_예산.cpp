#include <iostream>
using namespace std;

int nArr[10002];

void quick_sort(int first, int end)
{
	int pivotPoint = nArr[(first + end) / 2];

	int f = first;
	int e = end;

	while (f <= e)
	{
		while (pivotPoint > nArr[f]) f++;
		while (pivotPoint < nArr[e]) e--;

		if (f <= e)
		{
			int tmp = nArr[f];
			nArr[f] = nArr[e];
			nArr[e] = tmp;
			f++;
			e--;
		}
	}

	if (first < e) quick_sort(first, e);
	if (f< end) quick_sort(f, end);
}

int main()
{
	int N;
	int count;
	int budget;
	int sum = 0;
	int max = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> nArr[i];
	}

	cin >> budget;

	quick_sort(0, N - 1);

	for (int i = 0; i < N; i++)
	{
		if (sum + nArr[i] * (N-i) >= budget)
		{
			max = (budget - sum) / (N - i);
			break;
		}
		else
		{
			sum += nArr[i];
			max = nArr[i];
		}

	}

	cout << max << endl;

	return 0;
}