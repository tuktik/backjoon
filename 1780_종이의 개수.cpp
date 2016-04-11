#include <iostream>
//#include <math.h>

using namespace std;

int arr[3000][3000];

int dfs(int x, int y)
{
	return 0;
}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(0,0);
	
	

	return 0;
}