#include <iostream>
#include <limits.h>

using namespace std;

int numArr[405][405];

int main()
{
	int v;
	int e;

	cin >> v;
	cin >> e;

	int a, b, weight;

	for (int i = 0; i < e; i++)
	{
		cin >> a;
		cin >> b;

		cin >> weight;
		numArr[a][b] = weight;
	}

	for (int i = 1; i <=v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			for (int k = 1; k <= v; k++)
			{
				if (numArr[i][k] != 0 && numArr[k][j] != 0)
				{
					if (numArr[i][j] >= numArr[i][k] + numArr[k][j])
						numArr[i][j] = numArr[i][k] + numArr[k][j];
					else if (numArr[i][j]==0)
						numArr[i][j] = numArr[i][k] + numArr[k][j];
				}
			}
		}
	}

	int minVal = INT_MAX;
	bool flag = true;

	for (int i = 1; i <= v; i++)
	{
		if (numArr[i][i] != 0 && numArr[i][i] < minVal)
		{
			flag = false;
			minVal = numArr[i][i];
		}
			
	}

	if (flag == false)
		cout << minVal << endl;
	else
		cout << -1 << endl;
	return 0;
}