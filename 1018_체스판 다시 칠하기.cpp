#include <iostream>
using namespace std;

char chesArr[52][52];

int m, n;
int minCount = 64;


void compareW(int startM, int startN)
{
	int changeCount = 0;

	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				if (chesArr[startN + i][startM + j] == 'B')
				{
					changeCount++;
				}
			}
			else
			{
				if (chesArr[startN + i][startM + j] == 'W')
				{
					changeCount++;
				}
			}
			if (changeCount >= minCount)
				break;
		}
		if (changeCount >= minCount)
			break;
	}

	if (changeCount < minCount)
		minCount = changeCount;
}

void compareB(int startM, int startN)
{
	int changeCount = 0;

	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				if (chesArr[startN + i][startM + j] == 'W')
				{
					changeCount++;
				}
			}
			else
			{
				if (chesArr[startN + i][startM + j] == 'B')
				{
					changeCount++;
				}
			}
			if (changeCount >= minCount)
				break;
		}
		if (changeCount >= minCount)
			break;
	}

	if (changeCount < minCount)
		minCount = changeCount;
}

int main()
{


	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> chesArr[i][j];
		}
	}

	for (int startN = 0; startN <= n - 8; startN++)
	{
		for (int startM = 0; startM <= m - 8; startM++)
		{
			compareB(startM, startN);
			compareW(startM, startN);
		}
	}


	cout << minCount << endl;

	return 0;
}