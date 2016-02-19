#include <iostream>

using namespace std;

int n;

int dp[1000005];
int minVal = 1000005;
void dfs(int n, int cnt)
{
	if (n == 1 && cnt < minVal)
	{
		minVal = cnt;
		return;
	}

	if (n <= 0)
		return;
	
	if (dp[n] != 0 && dp[n] < cnt)
		return;

	//cout << n << " " << cnt << endl;

	dp[n] = cnt;

	if(n%3==0)
	dfs(n / 3,cnt+1);
	if (n % 2 == 0)
	dfs(n / 2, cnt + 1);
	
	dfs(n - 1, cnt + 1);
}

int main()
{
	cin >> n;


	dfs(n, 0);

	cout << minVal << endl;
	return 0;
}