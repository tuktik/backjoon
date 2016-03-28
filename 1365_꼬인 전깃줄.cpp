#include <iostream>

using namespace std;

int arr[100005];
int dp[100000];
int n;


int main()
{
	

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		//dp[i] = 1;
	}

	int maxVal = 0;

	for (int i = 0; i < n; i++){
		dp[arr[i]] = dp[arr[i] - 1] + 1;
	}

	//cout << n - maxVal << endl;
	for (int i = 0; i < 5; i++){
		cout << dp[arr[i]] << " ";
	}
	//cout << endl;

	/*

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[j]>arr[i])
			{
				if (dp[j] >= dp[i])
					dp[i] = dp[j] + 1;
				
			}

			if (dp[i] > maxVal)
				maxVal = dp[i];
		}
	}*/
	
	/*for (int i = 0; i < n; i++)
	{
		cout << dp[i] << endl;
	}
*/
	//cout << n-maxVal << endl;


	return 0;
}