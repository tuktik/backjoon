#include <iostream>

using namespace std;

int numArr[1005];

int main()
{
	int testNum;
	cin >> testNum;
	for (int t = 0; t < testNum; t++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> numArr[i];

		int max = -999;

		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = i; j < n; j++)
			{
				sum += numArr[j];
				if (max < sum)
					max = sum;
			}
		}

		cout << max << endl;
	}
	

	return 0;
}