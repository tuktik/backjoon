#if 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int ax[4] = { 0, 1, 0, -1 }, ay[4] = { -1, 0, 1, 0 };
int m, n, M[501][501], DP[501][501];
int dp(int i, int j) {
	if (i == 0 && j == 0) return DP[i][j] = 1;
	if (DP[i][j] == 0)
		for (int k = 0; k < 4; k++) if (M[i + ay[k]][j + ax[k]] > M[i][j]) DP[i][j] += dp(i + ay[k], j + ax[k]);
	return DP[i][j];
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) scanf("%d", &M[i][j]);
	printf("%d\n", dp(m - 1, n - 1));
	return 0;
}
#endif

#include <iostream>

using namespace std;

int arr[501][501];
int dp[501][501];
int n, m;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int dfs(int x, int y)
{
	if (x<0 || y<0 || x>m || y>n) return 0;
	//if (x == 0 && y == 0) return dp[y][x] = 1;

	if (dp[y][x] != 0)
		return dp[y][x];

	int &ans = dp[y][x];
	if (dp[y][x] == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (arr[y][x]<arr[y + dy[i]][x + dx[i]])
				ans += dfs(x + dx[i], y + dy[i]);
		}
	}

	return ans;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;

	cout<<dfs(m-1,n-1)<<endl;


	return 0;
}


/*
int dfs(int i, int j) {
if (i == 0 && j == 0) return dp[i][j] = 1;
if (dp[i][j] == 0)
for (int k = 0; k < 4; k++) if (arr[i + dy[k]][j + dx[k]] > arr[i][j]) dp[i][j] += dfs(i + dy[k], j + dx[k]);
return dp[i][j];
}
*/