#include <iostream>

using namespace std;

int dp[1000005];

int min(int a, int b, int c)
{
	int tmp = a < b ? a : b;
	tmp = tmp < c ? tmp : c;

	return tmp;
}

int dfs(int n)
{
	if (n == 1)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	int a = 9999999, b = 9999999, c = 9999999;
	
	if (n%3==0)
		a= dfs(n / 3);
	if (n % 2 == 0)
		b = dfs(n / 2);
	c = dfs(n - 1);
	
	return dp[n] = 1+ min(a, b, c);
}

int main()
{
	int n;

	cin >> n;

	cout << dfs(n) << endl;

	/*for (int i = 1; i <=n; i++)
		cout <<i<<" "<< dp[i] << endl;*/

	return 0;
}