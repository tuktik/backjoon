#include <iostream>

using namespace std;

int n, s;
int arr[20];
int cnt = 0;

void dfs(int nowIdx, int sum, bool is_check)
{
	if (nowIdx > n)
		return ;

	if (sum == s && is_check == false)
	{
		is_check = true;
		cnt++;
	}
		

	
	dfs(nowIdx + 1, sum, is_check);
	dfs(nowIdx + 1, sum + arr[nowIdx],false);
}

int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dfs(0, 0, true);
	cout << cnt << endl;

	return 0;
}