#include <iostream>
#include <string.h>

using namespace std;

long long dp[35][35];

long long dfs(int w, int h)
{
	if (w == 0 && h == 0)
		return 1;
	
	if (w < 0)
		return 0;

	if (h < 0)
		return 0;

	if (dp[w][h] != -1)
		return dp[w][h];

	return dp[w][h] = dfs(w - 1, h + 1)+dfs(w,h-1);

}

int main()
{
	int t;
	cin >> t;

	while(t!=0)
	{

		memset(dp, -1, sizeof(dp));

		cout << dfs(t, 0) << endl;
		cin >> t;
	}


	return 0;
}