#include <iostream>

using namespace std;

int chessArr[301][301];
bool visited[301][301];

class pos
{
public:
	int x, y;
	int dept;

	pos(){}
	pos(int x, int y, int dept) :x(x), y(y), dept(dept){}
};

class que
{
	pos data[1000000];
	long long front, rear;

public:
	que() :front(0), rear(0){}

	void push(pos input)
	{
		data[rear++ % 1000000] = input;
	}

	pos pop()
	{
		return data[front++ % 1000000];
	}

	bool is_empty()
	{
		if (front == rear)
			return 1;
		else
			return 0;
	}
	void init()
	{
		front = 0;
		rear = 0;
	}

};

que public_que;

int dx[8] = { -1, -2, 1, 2, -1, -2, 1, 2 };
int dy[8] = { -2, -1, 2, 1, 2, 1, -2, -1 };

int destX, destY;
int nightX, nightY;
int i;


void init()
{
	for (int a = 0; a < 300; a++)
	{
		for (int b = 0; b < 300 ; b++)
		{
			visited[a][b] = 0;
		}
	}
}

int bfs()
{
	init();
	public_que.init();
	public_que.push(pos(nightX, nightY,0));
	
	visited[nightY][nightX] = 1;

	while (!public_que.is_empty())
	{
		pos tmp = public_que.pop();

		if (tmp.x == destX && tmp.y == destY)
		{
			return tmp.dept;
		}

		for (int d = 0; d < 8; d++)
		{
			if (tmp.x + dx[d] >= 0 && tmp.x + dx[d] <i && tmp.y + dy[d] >= 0 && tmp.y + dy[d] < i && visited[tmp.y + dy[d]][tmp.x + dx[d]] == 0)
			{
				public_que.push(pos(tmp.x + dx[d], tmp.y + dy[d], tmp.dept+1));

				visited[tmp.y + dy[d]][tmp.x + dx[d]] = 1;
			}
		}
	}
	//cout << "!!" << endl;
	return 0;
}

int main()
{
	int testNum;

	cin >> testNum;

	for (int a = 0; a < testNum; a++)
	{
		cin >> i;

		cin >> nightX;
		cin >> nightY;

		cin >> destX;
		cin >> destY;

		cout << bfs() << endl;
	}

	return 0;
}