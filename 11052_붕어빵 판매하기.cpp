#include <stdio.h>

int dp[1005];

int main()
{
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dp[i]);
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j >= i / 2; j--)
		{
			if (dp[i] < dp[j] + dp[i - j])
				dp[i] = dp[j] + dp[i - j];
		}
	}

	printf("%d", dp[n]);



	return 0;
}