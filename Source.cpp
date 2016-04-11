#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
#define mp(x,y) make_pair(x,y)


int N, M, X, A, B, dist;

vector<vector<pii> > redge, edge; //

int main()
{
	scanf("%d %d %d", &N, &M, &X);
	edge = redge = vector<vector<pii>>(N + 1);


	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &A, &B, &dist);
		edge[A].push_back(mp(B, dist));
		redge[B].push_back(mp(A, dist));
	}

	vector<int> GoDist(N + 1, -1); // 값이 -1인 원소 N+1개 보관
	vector<int> BackDist(N + 1, -1);

	priority_queue<pii> pq; // 
	
	BackDist[X] = 0;
	pq.push(mp(-BackDist[X], X));

	while (!pq.empty())
	{
		int nowPos = pq.top().second;
		int nowDist = -pq.top().first;
		
		pq.pop();
		for (int i = 0; i < edge[nowPos].size(); i++)
		{
			int tnowPos = edge[nowPos][i].first;
			int nodeDist = edge[nowPos][i].second;
			if (BackDist[tnowPos] == -1 || BackDist[tnowPos] > nowDist + nodeDist)
			{
				BackDist[tnowPos] = nowDist + nodeDist;
				pq.push(mp(-BackDist[tnowPos], tnowPos));
			}
		}
	}

	for (int i = 1; i <=N; i++)
		cout << BackDist[i] << endl;

	GoDist[X] = 0;
	pq.push(mp(GoDist[X], X));

	while (!pq.empty())
	{
		int nowPos = pq.top().second;
		int nowDist = -pq.top().first;
		pq.pop();
		for (int i = 0; i < redge[nowPos].size(); i++)
		{
			int tnowPos = redge[nowPos][i].first;
			int nextDist = nowDist + redge[nowPos][i].second;
			if (GoDist[tnowPos] == -1 || GoDist[tnowPos] > nextDist)
			{
				GoDist[tnowPos] = nextDist;
				pq.push(mp(-GoDist[tnowPos], tnowPos));
			}
		}
	}

	int sol = 0;
	for (int i = 1; i <= N; i++)
		sol = max(sol, GoDist[i] + BackDist[i]);
	printf("%d", sol);
}
