#include <iostream>

using namespace std;

int mazzArr[105][105];
int visited[105][105];
int n, m;

int min(int a, int b, int c, int d)
{
	int minVal = a<b?a:b;
	minVal = minVal<c ? minVal : c;
	minVal = minVal<d ? minVal : d;

	return minVal;
}

int dfs(int x, int y,int cnt)
{
	if (x >= m || x < 0)
		return 999999;
	if (y >= n || y < 0)
		return 999999;
	if (mazzArr[y][x] == 0)
		return 999999;

	if (x == m - 1 && y == n - 1)
		return 1;

	if (visited[y][x]>cnt || visited[y][x]==0)
	{
		visited[y][x] = cnt++;
		int a = dfs(x + 1, y, cnt);
		int b = dfs(x - 1, y, cnt);
		int c = dfs(x, y + 1, cnt);
		int d = dfs(x, y - 1, cnt);
		
		return 1 + min(a, b, c, d);
	}
	
	return 99999999;
}

int main()
{

	cin >> n;
	cin >> m;

	char tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			mazzArr[i][j] = (int)tmp - 48;
		}
	}
	
	cout << dfs(0, 0,0) << endl;

	return 0;
}