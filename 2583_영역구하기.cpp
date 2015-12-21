#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];
bool visited[101][101];

int outputArr[100];
int outputCount=0;
int rec_raw, rec_col;

class point
{
public:
	int x, y;
	point(){}
	point(int x, int y) :x(x), y(y){}
};

class queue
{
	point data[10000];
	int rear, front;

public:
	queue():front(0),rear(0){}
	void init()
	{
		front = 0;
		rear = 0;
	}
	void push(point input)
	{
		data[rear % 10000] = input;
		rear++;
	}
	point pop()
	{
		if (rear == front)
			return point(-1, -1);
		else
			return data[front++ % 10000];
	}
	bool is_notEmpty()
	{
		if (rear == front)
			return 0;
		else
			return 1;
	}

};

queue global_queue;

int bfs(int x, int y)
{
	
	global_queue.push(point(x, y));
	visited[y][x] = 1;
			
	int count = 0;

	while(global_queue.is_notEmpty())
	{
		point now_point = global_queue.pop();
		count++;
		//cout << now_point.x << " " << now_point.y << endl;
		
		if (now_point.x - 1 >= 0 && arr[now_point.y][now_point.x - 1] == 0 && visited[now_point.y][now_point.x - 1] == 0)
		{
			global_queue.push(point(now_point.x - 1, now_point.y));
			visited[now_point.y][now_point.x - 1] = 1;
		}
		if (now_point.x + 1 < rec_col && arr[now_point.y][now_point.x + 1] == 0 && visited[now_point.y][now_point.x + 1] == 0)
		{
			global_queue.push(point(now_point.x + 1, now_point.y));
			visited[now_point.y][now_point.x + 1] = 1;
		}
		if (now_point.y - 1 >= 0 && arr[now_point.y - 1][now_point.x] == 0 && visited[now_point.y - 1][now_point.x] == 0)
		{
			global_queue.push(point(now_point.x, now_point.y - 1));
			visited[now_point.y-1][now_point.x] = 1;
		}
		if (now_point.y + 1 < rec_raw && arr[now_point.y + 1][now_point.x] == 0 && visited[now_point.y + 1][now_point.x] == 0)
		{
			global_queue.push(point(now_point.x, now_point.y + 1));
			visited[now_point.y+1][now_point.x] = 1;
		}
			
	}
	return count;
}

int main()
{
	
	cin >> rec_raw >> rec_col;

	int rect_count;
	
	cin >> rect_count;

	int x1, y1;
	int x2, y2;

	for (int a = 0; a < rect_count; a++)
	{
		cin >> x1 >> y1;
		cin >> x2 >> y2;

		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < rec_raw; i++)
	{
		for (int j = 0; j < rec_col; j++)
		{
			//cout << arr[i][j]<<" ";
			int res=0;
			if (visited[i][j] == 0 && arr[i][j] == 0)
			{
				res = bfs(j, i);
			}
			if (res != 0)
			{
				outputArr[outputCount] = res;
				outputCount++;
			}
		}
	}

	cout << outputCount << endl;
	
	sort(outputArr, outputArr+outputCount);

	for (int i = 0; i < outputCount; i++)
		cout << outputArr[i] << " ";
	cout << endl;

	return 0;
}