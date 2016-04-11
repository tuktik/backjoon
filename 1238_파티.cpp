// 플로이드 워셜
#include <iostream>

using namespace std;

int distArr[1001][1001];

int main()
{
	int n, m, x;
	// n은 학생수(마을의 수)
	// m은 도로
	// x는 모이는 마을

	cin >> n >> m >> x;

	int start;
	int end;
	int dist;

	for (int i = 0; i < m; i++)
	{
		cin >> start;
		cin >> end;
		cin >> dist;

		distArr[start][end] = dist;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (distArr[i][j] == 0)
				distArr[i][j] = 9999999;
			//cout << distArr[i][j] << " ";
		}
		//cout << endl;
	}

	/*if (i == j)
	continue;*/
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (distArr[i][k] == 9999999)	continue;
			for (int j = 1; j <= n; j++)
			{
				if (i == k || j == k || i==j)
					continue;
				if (distArr[i][j]> distArr[i][k] + distArr[k][j])
					distArr[i][j] = distArr[i][k] + distArr[k][j];


			}
		}
	}

	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		if (i != x)
		{
			
			if (max < distArr[i][x] + distArr[x][i])
				max = distArr[i][x] + distArr[x][i];
		}

	}

	cout << max << endl;

	return 0;
}

// 다익스트라
#if 0
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
#define mp(x,y) make_pair(x,y)

int n, m, x;
int a, b, dist;
int goDist[1005];
int backDist[1005];

int main()
{
	cin >> n >> m >> x;

	vector<vector<pii > > edge(n + 1);
	vector<vector<pii > > redge(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> dist;

		edge[a].push_back(mp(b, dist));
		redge[b].push_back(mp(a, dist));
	}

	
	priority_queue<pii> pq;
	memset(goDist, -1, sizeof(goDist));

	goDist[x] = 0;
	pq.push(mp(-goDist[x],x));

	while (!pq.empty())
	{
		int nowDist = -pq.top().first;
		int nowPos = pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[nowPos].size(); i++)
		{
			int nextNode = edge[nowPos][i].first;
			int nodeDist = edge[nowPos][i].second;

			if (goDist[nextNode] == -1 || goDist[nextNode]> nowDist + nodeDist)
			{
				goDist[nextNode] = nowDist + nodeDist;
				pq.push(mp(-goDist[nextNode], nextNode));
			}
		}
	}


	memset(backDist, -1, sizeof(backDist));
	backDist[x] = 0;
	pq.push(mp(-backDist[x], x));

	while (!pq.empty())
	{
		int nowDist = -pq.top().first;
		int nowPos = pq.top().second;
		pq.pop();

		for (int i = 0; i < redge[nowPos].size(); i++)
		{
			int nextNode = redge[nowPos][i].first;
			int nodeDist = redge[nowPos][i].second;

			if (backDist[nextNode] == -1 || backDist[nextNode]> nowDist + nodeDist)
			{
				backDist[nextNode] = nowDist + nodeDist;
				pq.push(mp(-backDist[nextNode], nextNode));
			}
		}
	}
	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		//cout << goDist[i] <<" "<< backDist[i] << endl;
		if (max < goDist[i] + backDist[i] )
		{
			max = goDist[i] + backDist[i];
		}
	}
	cout << max << endl;

	return 0;
}
#endif