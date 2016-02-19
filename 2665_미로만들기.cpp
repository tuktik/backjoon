#include <iostream>
#include <queue>
using namespace std;

int n;
int minCnt = 2500;

bool roomArr[55][55];
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
	
	while (!global_queue.empty())
	{
		pos temp = global_queue.front();
		global_queue.pop();

		for (int i = 0; i < 4; i++)
		{
			if (temp.x + dx[i]<n && temp.x + dx[i]>=0 && visited[y][x]<temp.chngRoom+1)
		}
		

	}
	



}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> roomArr[i][j];
		}
	}




	return 0;
}