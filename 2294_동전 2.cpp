#include <iostream>
#include <cstring>

using namespace std;

int n, k;
int dp[10001];
int arr[101];

int main()
{
	cin >> n >> k;

	int now_num;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
		
	for (int i = 0; i < n; i++)
	{
		for (int j = arr[i]; j <= k; j++)
		{
			if (j == arr[i])
				dp[j] = 1;
			else if (dp[j - arr[i]]!= -1)
			{
				//if (dp[j]>dp[j - arr[i]] + 1 || dp[j]==-1)
				dp[j] = dp[j - arr[i]] + 1;
				
			}
			
		}
	}
	
	for (int i = 1; i <= k; i++)
		cout << dp[i] << endl;

	return 0;
}