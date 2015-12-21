#include <iostream>

using namespace std;

int arr[51][51];
bool visited[51][51];

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
	int front, rear;

public:

	queue() :front(0), rear(0){}

	void init()
	{
		front = 0;
		rear = 0;
	}

	void push(point input)
	{
		data[rear % 10000];
		rear++;
	}

	point pop()
	{
		if (front == rear)
		{
			return point(-1, -1);
		}
		else
		{
			return data[front++ % 10000];
		}
	}
};

queue global_queue;

void bfs(int arr_size)
{
	


}
int main()
{
	int arr_size;

	cin >> arr_size;
	
	for (int i = 1; i <= arr_size; i++)
	{
		for (int j = 1; j <= arr_size; j++)
		{
			cin >> arr[i][j]; 
		}
	}

	bfs(arr_size);




	return 0;
}