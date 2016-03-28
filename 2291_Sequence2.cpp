#include <iostream>

using namespace std;

int n, m, k;
int dp[11][221][221];
int cnt = 0;
int res[11];

int Func(int pos, int before, int sum)
{
	if (sum > m) return 0;

	if (pos == n)
	{
		if (sum == m){
			cnt++;
			if (cnt == k)
			{
				for (int i = 0; i< n; i++)
					cout << res[i] << " ";
				exit(0);
			}
			return 1;
		}
		return 0;
	}

	int &ans = dp[pos][before][sum];

	if (ans != -1 && cnt + ans < k){
		cnt += ans;
		return ans;
	}

	ans = 0;

	for (int i = before; i <= m - sum; i++){
		res[pos] = i;
		ans += Func(pos + 1, i, sum + i);
	}
	return ans;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	Func(0, 1, 0);
}