#include <iostream>
#include <stdio.h>

using namespace std;

int arr[105][105];
int n;
long long cntArr[105][105];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			//cout << "!";
		}
	}


	cntArr[0][0] = 1;

	for (int i = 0; i <= (2*n - 2); i++)
	{
		for (int j = i, k = 0; j >= 0; j--, k++)
		{
			if (j>n - 1 || k > n - 1)
				continue;
			//cout << k << " " << j << endl;
			if (arr[j][k]==0)
				continue;
			int nowVal = arr[j][k];
			if (j+nowVal<n)
			cntArr[j + nowVal][k] += cntArr[j][k];
			if (k + nowVal<n)
			cntArr[j][k + nowVal] += cntArr[j][k];
				
		}

	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << cntArr[i][j]<<" ";
		}
		cout << endl;
	}*/


	cout << cntArr[n - 1][n - 1] << endl;


	return 0;
}