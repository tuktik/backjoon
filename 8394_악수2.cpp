#include <iostream>
#include <string.h>

using namespace std;

long long dp[10000005];

int dfs(int idx, int n)
{
	if (idx > n)
		return 0;

	if (idx == n)
		return 1;

	if (dp[idx] != -1)
		return dp[idx]%10;
	
	return dp[idx] = (dfs(idx + 1, n) + dfs(idx + 2, n))%10;

}

int main()
{
	int n;
	cin >> n;

	memset(dp, -1, sizeof(int)*n);
	
	cout << dfs(0, n) << endl;

	return 0;
}