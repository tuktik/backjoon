#include <iostream>

using namespace std;

void sort(int * Arr, int first, int end)
{
	int pivot = Arr[(first + end) / 2];

	int f = first;
	int e = end;

	while (f <= e)
	{
		while (Arr[f] < pivot)f++;
		while (Arr[e] > pivot)e--;

		if (f <= e)
		{
			int temp = Arr[f];
			Arr[f] = Arr[e];
			Arr[e] = temp;

			f++;
			e--;
		}
	}

	if (f < end)
		sort(Arr, f, end);
	if (first<e)
		sort(Arr, first, e);

}

bool binary_search(int* Arr, int first, int end, int number)
{
	int pivotIndex = (first + end) / 2;
		
	if (first > end)
		return false;

	if (Arr[pivotIndex] == number)
	{
		return true;
	}
	else if (Arr[pivotIndex] > number)
	{
		return binary_search(Arr, first, pivotIndex-1, number);
	}
	else if (Arr[pivotIndex] < number)
	{
		return binary_search(Arr, pivotIndex + 1, end, number);
	}
}

int main()
{
	int m_count;
	int n_count;
	int mArr[100001];

	int nArr[100001];
	
	cin >> m_count;
	for (int i = 0; i < m_count; i++)
	{
		cin >> mArr[i];
	}
	cin >> n_count;
	for (int i = 0; i < n_count; i++)
	{
		cin >> nArr[i];
	}

	sort(mArr, 0, m_count - 1);

	for (int i = 0; i < n_count; i++)
	{
		if (binary_search(mArr, 0, m_count-1, nArr[i]) == true)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	

	return 0;
}