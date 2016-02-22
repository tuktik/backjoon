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

	if (dp[idx] != 0)
		return dp[idx];
	
	dp[idx] = (dfs(idx + 1, n) + dfs(idx + 2, n)) % 10007;
	
	return dp[idx];
}

int main()
{
	int n;

	cin >> n;
	
	//memset(dp, -1, sizeof(int)*n);
	
	cout<< dfs(0, n)%10007<<endl;
	
	for (int i = 0; i <=n; i++)
		cout << dp[i] << endl;
	
	//cout << min << endl;
	return 0;
}

//int getMin(int a,int b)
//{
//	return a < b ? a : b;
//}
//int dfs2(int idx, int n, int count)
//{
//	if (idx == n)
//	{
//		return count;
//	}
//	else if (idx > n)
//		return 99999999;
//
//	return getMin(dfs2(idx + 1, n, count + 1) , dfs2(idx + 2, n, count + 1));
//}