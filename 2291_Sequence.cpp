#include <iostream>
#include <cstdlib>

using namespace std;

int dp[15][225][225];
int arr[11];
int n, m, k;
long long kCnt = 0;

int dfs(int now_idx, int before, int sumVal)//, int kCnt
{
	if (sumVal > m || now_idx > n)
		return 0;
	
	if ( now_idx == n )
	{
		if (sumVal == m)
		{
			kCnt += 1;
			if (kCnt == k)
			{
				for (int i = 1; i <= n; i++)
				{
					cout << arr[i] << " ";
				}
				exit(0);
			}
			return 1;
		}
		return 0;
	}
	
	//cout << now_idx << " " << before << " " << sumVal << endl;
	int &ans = dp[now_idx][before][sumVal];
	
	if (ans != 0 && kCnt + ans<k)
	{
		//cout << dp[m - sumVal][n - now_idx] << endl;
		kCnt += ans;
		return ans;
	}
		
	
	for (int i = before; i <= m-sumVal; i++)
	{
			arr[now_idx+1] = i;
			ans += dfs(now_idx + 1, i,sumVal + i);
		
	}
	
	return ans;

}

int main()
{
	

	cin >> n >> m >> k;

	dfs(0, 1, 0);
	
	//cout << dfs(0, 0) << endl;

	/*for (int i = 0; i <=m; i++)
	{
		for (int j = 0; j <=n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}