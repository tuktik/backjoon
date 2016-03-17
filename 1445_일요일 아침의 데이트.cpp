#include <iostream>
#include <queue>

using namespace std;


char parkArr[55][55];
int dp[55][55][2];
int weight[55][55];
int n, m;

void init()
{

}


class point
{
public:
	int x, y;

	point() {}
	point(int x, int y) :x(x), y(y) {}
};


queue<point> global_queue;
int strt_x, strt_y;
int pntF_x, pntF_y;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


void bfs()
{
	global_queue.push(point(strt_x, strt_y));

	while (!global_queue.empty())
	{
		point tmp = global_queue.front();
		global_queue.pop();

		if (tmp.x == pntF_x && tmp.y == pntF_y)
			continue;




	}


}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> parkArr[i][j];

			if (parkArr[i][j] == 'S')
			{
				strt_x = j;
				strt_y = i;
			}
			else if (parkArr[i][j] == 'F')
			{
				pntF_x = i;
				pntF_y = j;
			}
			else if (parkArr[i][j] == 'g')
			{
				for (int a = 0; a < 4; a++)
				{
					if (j + dx[a] >= 0 && j + dx[a] < m && i + dy[a] >= 0 && i + dy[a] < n)
					{
						weight[i + dy[a]][j + dx[a]]++;
					}
				}
			}
			else
				dp[i][j][0] = 9999999;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << weight[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}