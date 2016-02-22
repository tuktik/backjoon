#include <iostream>
#include <string.h>
using namespace std;

int min = 9999999999;

int dp[1005];

int dfs(int idx, int n)
{
	if (idx == n)
	{
		return 1;
	}
	else if (idx > n)
		return 0;

	if (dp[idx] != -1)
		return dp[idx];

	dp[idx] = dfs(idx + 1, n) + 2*dfs(idx + 2, n) % 10007;

	return dp[idx];
}

int main()
{
	int n;

	cin >> n;

	memset(dp, -1, sizeof(int)*n);
	
	cout << dfs(0, n) % 10007 << endl;
	//cout << min << endl;
	return 0;
}