#include <iostream>
#include <queue>
using namespace std;

int box[102][102][102];
int visited[102][102][102];
int m, n, h;

class point
{
public:
	int mM, mN, mH;
	point(int m, int n, int h) :mM(m), mN(n), mH(h){};

};

queue<point> global_que;

void bfs(int m, int n, int h)
{
	
}

int main()
{
	cin >> m >> n >> h;

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				cin >> box[i][j][k];
				//if (box[i][j][k] == 1)
					
			}
		}
	}

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				if (box[i][j][k] == 1 && visited[i][j][k] == 0)
				{
					global_que.push(point(k, j, i));
					bfs(k, j, i);
				}

			}
		}
	}


	return 0;
}