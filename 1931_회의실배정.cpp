#include <iostream>

using namespace std;


int arr[100005][2];
int dp[100005];

void quick(int first, int end)
{
	int pivot[2];
	pivot[0] = arr[(first + 2) / 2][0];
	pivot[1] = arr[(first + 2) / 2][1];
	int f = first;
	int e = end;

	while (f <= e)
	{
		while (arr[f][0] < pivot[0] || (arr[f][0] == pivot[0] && arr[f][1] < pivot[1])) f++;
		while (pivot[0] < arr[e][0]  || (arr[e][0] == pivot[0] && arr[e][1] > pivot[1])) e--;

		if (f <= e)
		{
			int tmp[2];
			tmp[0] = arr[f][0];
			tmp[1] = arr[f][1];
			arr[f][0] = arr[e][0];
			arr[f][1] = arr[e][1];
			arr[e][0] = tmp[0];
			arr[e][1] = tmp[1];
			
			f++;
			e--;
		}
	}

	if (first < e)quick(first, e);
	if (f < end) quick(f, end);
}

int main()
{
	int n;

	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0];
		cin >> arr[i][1];
	}

	quick(1, n);


	
	
	return 0;
}