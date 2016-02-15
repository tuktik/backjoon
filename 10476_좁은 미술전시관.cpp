#include <iostream>

#define ROOIDX 205
#define STATE 3
#define	CLOSEDROOMCOUNT 205

using namespace std;

int roomArr[205][2];
int chkArr[ROOIDX][STATE][CLOSEDROOMCOUNT];
int n;
int k;
int maxSum = 0;

//int roopCount = 0;

void dfs(int idx, int state, int closeCount, int now_sum)
{
	//printf("idx:%d state:%d prev_state:%d closeCount:%d now_sum:%d\n", idx, state, prev_state, closeCount, now_sum);
	if (idx > n)
		return;
	if (closeCount > n || closeCount > k)
		return;

	if (maxSum < now_sum && closeCount == k)
	{
		maxSum = now_sum;
		/*printf("idx:%d state:%d closeCount:%d now_sum:%d\n", idx, state, closeCount, now_sum);
		cout << "maxSum" << maxSum << endl;
		cout << "chkArr!" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << chkArr[i][0] << " " << chkArr[i][1] << endl;;
		}*/
	}
	
	if (chkArr[idx][state][closeCount] > now_sum)
	{
		return;
	}
	else
	{
		chkArr[idx][state][closeCount] = now_sum;
	}
	//roopCount++;
	dfs(idx + 1, 0, closeCount, now_sum + roomArr[idx][0] + roomArr[idx][1]);

	if (state == 0)
	{
		dfs(idx + 1, 1, closeCount + 1, now_sum + roomArr[idx][0] );
		dfs(idx + 1, 2, closeCount + 1, now_sum + roomArr[idx][1]);
	}
	else if (state == 1)
	{
		dfs(idx + 1, 1, closeCount + 1, now_sum + roomArr[idx][0]);
	}
	else
	{
		dfs(idx + 1, 2, closeCount + 1, now_sum + roomArr[idx][1]);
	}
}

int main()
{
	cin >> n;
	cin >> k; 

	for (int i = 0; i <n; i++)
	{
		cin >> roomArr[i][0];
		cin >> roomArr[i][1];
	}

	dfs(0, 0, 0, 0);

	cout << maxSum << endl;
	//cout << roopCount << endl;

	return 0;
}