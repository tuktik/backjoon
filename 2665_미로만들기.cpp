#include <iostream>
#include <queue>
using namespace std;

int n;
int minCnt = 2500;

int roomArr[55][55];
int visited[55][55];

class pos
{
public:
	int x;
	int y;
	int chngRoom;

	pos(int x, int y, int chngRoom) :x(x), y(y), chngRoom(chngRoom){}
};

queue<pos> global_queue;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(int x, int y, int Cnt)
{
	global_queue.push(pos(x, y, Cnt));
	visited[y][x] = 1 - roomArr[y][x];


	while (!global_queue.empty())
	{
		pos temp = global_queue.front();
		global_queue.pop();
		cout << temp.x << " " << temp.y <<" "<< temp.chngRoom << endl;

		for (int i = 0; i < 4; i++)
		{
			if (temp.x + dx[i] < n && temp.x + dx[i] >= 0
				&& temp.y + dy[i] < n && temp.y + dy[i] >= 0)
			{
				if (visited[temp.y + dy[i]][temp.x + dx[i]]== -1)
				{
					if (temp.x + dx[i] == 2 && temp.y + dy[i] == 1)
						cout << roomArr[y + dy[i]][x + dx[i]]<<"!" << endl;
					global_queue.push(pos(temp.x + dx[i], temp.y + dy[i], temp.chngRoom + 1 - roomArr[y + dy[i]][x + dx[i]]));
					visited[temp.y + dy[i]][temp.x + dx[i]] = temp.chngRoom + 1 - roomArr[y + dy[i]][x + dx[i]];
				}
				else if (visited[temp.y + dy[i]][temp.x + dx[i]] >= temp.chngRoom + 1 - roomArr[y + dy[i]][x + dx[i]])
				{
					global_queue.push(pos(temp.x + dx[i], temp.y + dy[i], temp.chngRoom + 1 - roomArr[y + dy[i]][x + dx[i]]));
					visited[temp.y + dy[i]][temp.x + dx[i]] = temp.chngRoom + 1 - roomArr[y + dy[i]][x + dx[i]];
				}
			}
		}	

	}

}

int main()
{
	cin >> n;
	
	char tmp;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			cin >> tmp;
			roomArr[i][j] = (int)tmp-48;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << roomArr[i][j] << " ";
			//visited[i][j] = -1;
		}
		cout << endl;
	}

	bfs(0, 0, 1 - roomArr[0][0]);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << visited[n - 1][n - 1] << endl;


	return 0;
}