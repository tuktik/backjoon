#include <iostream>

using namespace std;

int n;
int k;

int numArr[101];
int dp[10001];


int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> numArr[i];

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = numArr[i]; j <= k; j++)
		{
			dp[j] += dp[j - numArr[i]];
		}
	}

	cout << dp[k] << endl;
	


	return 0;
}