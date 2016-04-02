#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
#define mp(x,y) make_pair(x,y)


int N, M, X,A,B,D;

vector<vector<pii> > redge,edge;

int main()
{
	scanf("%d %d %d", &N, &M, &X);
	edge = redge = vector<vector<pii> >(N + 1);


	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &A, &B, &D);
		redge[B].push_back(mp(A, D));
		edge[A].push_back(mp(B, D));
	}

	vector<int> GoDist(N + 1, -1); // 값이 -1인 원소 N+1개 보관
	vector<int> BackDist(N + 1, -1);

	priority_queue<pii> pq; // 
	GoDist[X] = 0;
	pq.push(mp(GoDist[X], X));

	while (!pq.empty())
	{
		int here = pq.top().second, nowDist = -pq.top().first;
		pq.pop();
		for (int i = 0; i < redge[here].size(); i++)
		{
			int there = redge[here][i].first,nextDist=nowDist + redge[here][i].second;
			if (GoDist[there] == -1 || GoDist[there] > nextDist)
			{
				GoDist[there] = nextDist;
				pq.push(mp(-GoDist[there], there));
			}
		}
	}
	
	BackDist[X] = 0;
	pq.push(mp(-BackDist[X], X));
	
	while (!pq.empty())
	{
		int here = pq.top().second, nowDist = -pq.top().first;
		pq.pop();
		for (int i = 0; i < edge[here].size(); i++)
		{
			int there = edge[here][i].first, nextDist = nowDist + edge[here][i].second;
			if (BackDist[there] == -1 || BackDist[there] > nextDist)
			{
				BackDist[there] = nextDist;
				pq.push(mp(-BackDist[there], there));
			}
		}
	}
	int sol = 0;
	for (int i = 1; i <= N; i++)
		sol = max(sol, GoDist[i]+BackDist[i]);
	printf("%d", sol);
}


#if 0
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int distArr[1001][1001];
int nodeToX[1001];
int xToNode[1001];

int check[1001];

int main()
{
	int n, m, x;
	// n은 학생수(마을의 수)
	// m은 도로
	// x는 모이는 마을

	scanf("%d %d %d", &n, &m, &x);
	//cin >> n >> m >> x;

	int start;
	int end;
	int dist;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &start, &end, &dist);

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
	
	queue<int> djQueue;

	djQueue.push(x);

	while (!djQueue.empty())
	{
		int nowps = djQueue.front();
		djQueue.pop();

		for (int i = 1; i < n; i++)
		{
			if (nowps == i)
				continue;
			
			nodeToX[i] != 0;

			djQueue.

		}

		
	}

	int max = 0;

	printf("%d\n", max);
	//cout << max << endl;

	return 0;
}

/*
for (int i = 1; i <= n; i++)
{
for (int j = 1; j <= n; j++)
{
if (i == j)
continue;
for (int k = 1; k <= n; k++)
{
if (i == k || j==k)
continue;
if (distArr[i][j]> distArr[i][k] + distArr[k][j])
distArr[i][j] = distArr[i][k] + distArr[k][j];
}
}
}




for (int i = 1; i <= n; i++)
{
if (i != x)
{
if (max < distArr[i][x] + distArr[x][i])
max = distArr[i][x] + distArr[x][i];
}

}
*/
#endif