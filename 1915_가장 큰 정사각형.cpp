#include <stdio.h>
#include <iostream>

using namespace std;

int n, m;

int arr[1005][1005];
int check[1005][1005];

int main()
{
	scanf(" %d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	bool flag = true;
	int cnt = 1;
	int max = 0;
	while (flag == true)
	{
		flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == cnt)
				{
					if (arr[i][j + 1] == cnt && arr[i + 1][j] == cnt && arr[i + 1][j + 1] == cnt)
					{
						flag = true;
						arr[i][j]++;
					}
					if (arr[i][j]>max)
						max = arr[i][j];

				}
			}
		}
		//cout << cnt << " ";
		cnt++;
	}
	

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
			
		}
		cout << endl;
	}*/


	cout << max*max << endl;




	return 0;
}