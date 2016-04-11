#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define mp(x,y) make_pair(x,y)

int arr[1001][1001];
int idxArr[1001];

typedef pair<int, int > pii;
priority_queue<pii > pq;

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cin >> arr[i][j];
			scanf(" %d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		sort(arr[i], arr[i] + m);
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	int maxIdx;
	int minIdx=0;

	int res = INT_MAX;
	
	int min = INT_MAX;
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		pq.push(mp(-arr[i][idxArr[i]], i));
		if (arr[i][idxArr[i]] < min)
		{
			min = arr[i][idxArr[i]];
			minIdx = i;
		}

		if (arr[i][idxArr[i]] >= max)
		{
			max = arr[i][idxArr[i]];
			maxIdx = i;
		}
	}

	while (!pq.empty() && !(idxArr[minIdx] >= m))// || 
	{
		min=-pq.top().first;
		minIdx = pq.top().second;
		pq.pop();
		
		//std::cout << min << " " << max << endl;
		
		if (res > max - min)
		{
			//cout << min << " " << max << endl;
			res = max - min;
		}
			

		idxArr[minIdx]++;

		if (arr[minIdx][idxArr[minIdx]] > max)
		{
			max = arr[minIdx][idxArr[minIdx]];
			maxIdx = minIdx;
		}
		pq.push(mp(-arr[minIdx][idxArr[minIdx]], minIdx));
	}

	cout << res << endl;


	return 0;
}