#include <iostream>

using namespace std;

int numArr[1000];
/*
void sort(int manCount)
{
	for (int i = 0; i < manCount; i++)
	{
		for (int j = i; j < manCount; j++)
		{
			if (numArr[i] > numArr[j])
			{
				int temp = numArr[i];
				numArr[i] = numArr[j];
				numArr[j] = temp;
			}
		}
	}

}
*/

void quick_sort(int first, int end)
{
	int pivot = (first + end) / 2;
	int f = first;
	int e = end;

	while (f <= e)
	{
		while (numArr[f] < numArr[pivot])f++;
		while (numArr[pivot] < numArr[e])e--;

		if (f <= e)
		{
			int temp = numArr[f];
			numArr[f] = numArr[e];
			numArr[e] = temp;

			f++;
			e--;
		}
	}
	if (first < e)quick_sort(first, e);
	if (f < end)quick_sort(f, end);
}

int main()
{
	int manCount;

	cin >> manCount;

	for (int i = 0; i < manCount; i++)
		cin >> numArr[i];

	quick_sort(0, manCount - 1);

	int sum = 0;

	for (int i = 0; i < manCount; i++)
	{
		//cout << numArr[i] << endl;
		sum += (manCount - i)*numArr[i];
		//cout << (manCount - i)*numArr[i] << endl;
	}
	/*for (int i = 51; i >=1; i--)
	{
		cout << i << " ";
	}
	cout << endl;*/

	cout << sum << endl;

	return 0;
}