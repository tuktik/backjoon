#include <iostream>
#include <stdio.h>

using namespace std;

int arr[100005][2];

bool upper_compare(int *a, int *b)
{
	if (a < b || (a[0]==b[0]&& a[1]<b[1]))
		return true;
	else
		return false;
}

bool lower_compare(int *a, int *b)
{
	if (a > b || (a[0] == b[0] && a[1]>b[1]))
		return true;
	else
		return false;
}

void quick(int first, int end, bool (*cmpr)(int *a, int *b))
{
	int pivot[2] = { arr[(first + end) / 2][0], arr[(first + end) / 2][1] };
	int f = first;
	int e = end;

	while (f <= e)
	{
		while (cmpr(arr[f], pivot))f++;
		while (cmpr(pivot,arr[e]))e--;

		if (f <= e)
		{
			int temp[2] = { arr[f][0], arr[f][1] };
			arr[f][0] = arr[e][0];
			arr[f][1] = arr[e][1];
			arr[e][0] = temp[0];
			arr[e][1] = temp[1];

			f++;
			e--;
		}
	}

	if (first < e) quick(first, e, cmpr);
	if (f < end) quick(f, end, cmpr);
}

int n;

void sort_2step()
{
	int j=0;
	for (int i = 1; i <=n; i++)
	{
		int k = 0;
		for (j = 1; arr[i][0] == arr[i + j][0] && i+j<=n; j++);
		if (j != 1)
		{
			if (arr[i - 1][1]<arr[i + k][1])
				quick(i, i + j - 1, upper_compare);
			else if (arr[i - 1][1] > arr[i + k][1])
				quick(i, i + j - 1, lower_compare);
			else if (arr[i - 1][1] == arr[i + k][1])
			{
				while (arr[i - 1][1] == arr[i + k][1])
					k++;
			}
		}	
	}
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int a = 0; a < t; a++)
	{
		scanf("%d", &n);
		for (int i = 1; i <=n; i++)
		{
			scanf("%d %d", &arr[i][0], &arr[i][1]);
		}

		quick(1, n , upper_compare);

		sort_2step();
		/*
		cout << endl;
		
		for (int i = 1; i <=n; i++)
		{
		cout << arr[i][0] << " " << arr[i][1] << endl;
		}*/

		int m;

		scanf("%d", &m);
		for (int i = 1; i <=m; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			
			printf("%d %d\n", arr[tmp][0], arr[tmp][1]);
			//cout << arr[tmp][0] << " " << arr[tmp][1] << endl;
		}

	}
	
	return 0;
}