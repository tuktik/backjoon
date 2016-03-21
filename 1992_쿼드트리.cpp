#include <iostream>

using namespace std;

char quadTree[65][65];

int check(int x, int y, int size)
{
	char firstValue = quadTree[y][x];
	
	//cout << firstValue;
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (firstValue != quadTree[i][j])
			{
				//cout << "!";
				return -1;
			}
		}
	}
	return firstValue-'0';
}

void dfs(int x,int y, int size)
{
	int res = check(x, y, size);
	if (res == -1)
	{
		cout << "(";
		dfs(x, y, size / 2);
		dfs(x + size / 2, y, size / 2);
		dfs(x, y+size / 2, size / 2);
		dfs(x + size / 2, y + size / 2, size / 2);
		cout << ")";
	}
	else
	{
		cout << res;
	}	
}


int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> quadTree[i][j];
		}
	}

	dfs(0, 0, n);

	return 0;
}