#include <iostream>

using namespace std;

int arr[14];
int k;
int outputArr[6];

void dfs(int nowidx, int cnt)
{
	if (nowidx > k)
		return;

	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << outputArr[i] << " ";
		cout << endl;

		return;
	}
	
	outputArr[cnt] = arr[nowidx];
	dfs(nowidx + 1, cnt+1);
	dfs(nowidx + 1, cnt);
}

int main()
{
	cin >> k;

	while (k != 0)
	{

		for (int i = 0; i < k; i++)
			cin >> arr[i];

		dfs(0,0);
		cout << endl;
		cin >> k;
	}


	return 0;
}