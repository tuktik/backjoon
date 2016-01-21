#include <iostream>
#include <string.h>

using namespace std;

char numArr[12];

void quick(int first, int end)
{
	int pivot = numArr[(first + end) / 2];
	int f = first;
	int e = end;

	while (f <= e)
	{
		while (numArr[f] > pivot) f++;
		while (pivot > numArr[e]) e--;

		if (f <= e)
		{
			char temp = numArr[f];
			numArr[f] = numArr[e];
			numArr[e] = temp;
			
			f++;
			e--;
		}
	}

	if (first < e) quick(first, e);
	if (f < end) quick(f, end);
}

int main()
{
	cin >> numArr;

	quick(0, strlen(numArr) - 1);

	cout << numArr << endl;
	

	return 0;
}