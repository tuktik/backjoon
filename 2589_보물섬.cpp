#include <iostream>

using namespace std;

char inputArr[51][51];
bool visited[51][51];
int raw, col;

class point
{
public:
	int x, y;
	int dept;

	point(){}
	point(int x, int y, int dept) :x(x), y(y), dept(dept){}
};

class queue
{
	point Data[10000];
	int front, rear;

public:
	queue() :front(0), rear(0){}
	void push(point input)
	{
		Data[rear % 10000] = input;
		rear++;
	}
	
	point pop()
	{
		if (front == rear)
		{
			return point(-1, -1, -1);
		}
		else
		{
			return Data[front++ % 10000];
		}
	}
	
	bool is_notEmpty()
	{
		if (front == rear)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

queue global_queue;

int Dx[4] = { 0, 1, 0, -1 };
int Dy[4] = { 1, 0, -1, 0 };

int bfs(int x, int y)
{
	
	global_queue.push(point(x, y,0));
	visited[y][x] = 1;

	int max = 0;

	point tmp;
	while (global_queue.is_notEmpty())
	{
		point tmp = global_queue.pop();
		//cout << tmp.x << " " << tmp.y << " " << tmp.dept << endl;
		if (tmp.dept > max)
			max = tmp.dept;
		for (int i = 0; i < 4; i++)
		{
			if (visited[tmp.y + Dy[i]][tmp.x + Dx[i]] == 0
				&& inputArr[tmp.y + Dy[i]][tmp.x + Dx[i]] == 'L')
			{
				global_queue.push(point(tmp.x + Dx[i], tmp.y + Dy[i], tmp.dept + 1));
				visited[tmp.y + Dy[i]][tmp.x + Dx[i]]=1;
			}
		}
	}
	return max;
}

void init()
{
	for (int i = 1; i <= raw; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			visited[i][j] = 0;
		}
	}
}


int main()
{
	

	cin >> raw >> col;

	for (int i = 1; i <= raw; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			cin >> inputArr[i][j];
		}
	}

	int max = 0;
	for (int i = 1; i <= raw; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (inputArr[i][j] == 'L')
			{
				init();
				int res = bfs(j, i);
				if (max < res)
					max = res;
			}
		}
	}

	cout << max << endl;
	
	return 0;
}