#include <iostream>

using namespace std;

int arr[1005][1005];
int dp[1005][1005];

int max(int a, int b, int c)
{
	int tmp = a > b ? a : b;
	tmp = tmp > c ? tmp : c;
	
	return tmp;
}

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=m; j++)
		{
			int maxVal = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
			if (dp[i][j] < maxVal + arr[i][j])
			{
				dp[i][j] = maxVal + arr[i][j];
			}
		}
	}

	cout << dp[n][m] << endl;



	return 0;
}