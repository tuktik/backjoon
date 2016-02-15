#include <iostream>
#include <queue>

using namespace std;

int jumpArr[1005];
int dp[1005];
int num;

queue<int> global_queue;

void bfs()
{

	while (!global_queue.empty())
	{
		int now_val = global_queue.front();
		global_queue.pop();
		//cout << jumpArr[now_val] << endl;
		for (int j = jumpArr[now_val]; j >= 1; j--)
		{
			//cout <<	"!" << endl;
			if (dp[now_val + j] == 0)
			{
				dp[now_val + j] = dp[now_val] + 1;
				global_queue.push(now_val + j);
			}
		}
	}
}

int main()
{
	cin >> num;

	if (num == 1)
	{
		cout << 0 << endl;
		return 0;
	}
		

	for (int i = 0; i < num; i++)
	{
		cin >> jumpArr[i];
	}

	for (int j = jumpArr[0]; j >=1 ; j--)
	{
		global_queue.push(j);
		//cout << j <<"!"<< endl;
		dp[j] += 1;
	}

	/*for (int i = 1; i < num; i++)
	{
		for (int j = 1; j <= jumpArr[i]; j++)
		{
			if (dp[i + j] > dp[i] + 1 || dp[i + j]==0)
				dp[i + j] = dp[i] + 1;
		}
	}*/
	bfs();
	/*for (int i = 0; i < num; i++)
	{
		cout << dp[i] << endl;
	}*/

	if (dp[num - 1] == 0)
		cout << -1 << endl;
	else
		cout << dp[num - 1] << endl;
	


	return 0;
}