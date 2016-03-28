#include <iostream>

using namespace std;


int dp[15];
int n;

int dfs(int now_val)
{
	if (now_val == n)
		return 1;
	
	if (now_val > n)
		return 0;

	if (dp[now_val] != 0)
		return dp[now_val];

	return dp[now_val] = dfs(now_val + 1) + dfs(now_val + 2) + dfs(now_val + 3);
}

int main()
{
	int t;

	cin >> t;

	while (t--)
	{
		cin >> n;

		cout << dfs(0) << endl;
		
		for (int i = 0; i <= n; i++)
			dp[i] = 0;

	}


	return 0;
}


#if 0
#include <iostream>
#include <string.h>
using namespace std;

int min = 99999999;

int dp[1005];

int dfs(int idx, int n)
{
	if (idx == n)
	{
		return 1;
	}
	else if (idx > n)
		return 0;

	if (dp[idx] != 0)
		return dp[idx];

	dp[idx] = dfs(idx + 1, n) + dfs(idx + 2, n) + dfs(idx + 3, n);

	return dp[idx];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;

		cin >> n;

		//memset(dp, -1, sizeof(int)*n);

		cout << dfs(0, n) << endl;

		for (int i = 0; i <= n; i++)
		{
			dp[i] = 0;
		}
	}


	/*for (int i = 0; i <= n; i++)
	cout << dp[i] << endl;*/

	//cout << min << endl;
	return 0;
}

#endif