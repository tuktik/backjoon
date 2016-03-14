#include <iostream>
#include <string.h>

using namespace std;

int numArr[1005];
int dp[1005][2];

int max(int a, int b)
{
	return a > b ? a : b;
}
int dfs(int idx, int prev_idx,int dept, int n)
{
	if (idx == n+1)
		return dept;
	
	if (idx > n+1)
		return 0;
	

	if (dp[idx + 1][0] != 0 || dp[idx + 1][1] !=0)
		return dp[idx + 1][0] + dp[idx + 1][1];

	if (numArr[prev_idx] < numArr[idx])
	{
		return max(dp[idx][1] = dfs(idx + 1, idx, dept + 1, n), dp[idx][0] = dfs(idx + 1, prev_idx, dept, n));
	}

	return dp[idx][0] = dfs(idx + 1, prev_idx, dept, n);
}

int main()
{
	int n;

	cin >> n;

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++)
		cin >> numArr[i];

	cout << dfs(1, 0, 0, n) << endl;

	/*for (int i = 0; i <= n; i++)
	{
		cout << dp[i][0] << endl;
		cout << dp[i][1] << endl;
	}*/


	return 0;
}