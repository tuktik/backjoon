#include <iostream>

using namespace std;

int numArr[100001];

int main()
{
	int n;
	int s;

	cin >> n >> s;

	int sum = 0;
	int cnt = 0;

	int minval = 99999;

	for (int i = 0; i < n; i++)
	{
		cin >> numArr[i];
		
		sum += numArr[i];
		cnt++;

		if (sum >= s)
		{
			while (sum >= s)
			{
				if (sum - numArr[i - cnt + 1] < s)
					break;
				else
				{
					sum -= numArr[i - cnt + 1];
					cnt--;
				}
			}
			if (minval > cnt)
			{
				//cout << i << " " << cnt << endl;
				minval = cnt;
			}
				
		}
	}

	if (minval != 99999)
		cout << minval << endl;
	else
		cout << 0 << endl;




	return 0;
}