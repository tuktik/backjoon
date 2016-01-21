#include <iostream>

using namespace std;

//int arr[100002];
bool visited[100002];
int brother;
bool complete = false;
int res;

template <typename T>
class queue
{
	T data[100002];
	int front, rear;
public:
	queue() :front(0), rear(0){}

	void push(T input)
	{
		data[rear++] = input;
	}

	T pop()
	{
		return data[front++];
	}

	bool is_empty()
	{
		if (front == rear)
			return 1;
		else
			return 0;
	}
};

class point_dept
{
public:
	int point;
	int dept;
	point_dept(){}
	point_dept(int point, int dept) : point(point), dept(dept){}
	
};

queue<point_dept> public_queue;

int bfs(int now_index, int brother)
{
	point_dept subin(now_index, 0);
	public_queue.push(subin);
	visited[now_index] = 1;

	while (!public_queue.is_empty())
	{
		point_dept temp = public_queue.pop();

		if (temp.point == brother)
			return temp.dept;

		if (temp.point - 1 >=0 && visited[temp.point - 1] == 0)
		{
			public_queue.push(point_dept(temp.point - 1, temp.dept + 1));
			visited[temp.point - 1] = 1;
		}
			
		if (temp.point + 1 <=100000 && visited[temp.point + 1] == 0)
		{ 
			public_queue.push(point_dept(temp.point + 1, temp.dept + 1));
			visited[temp.point + 1] = 1;
		}
			

		if (temp.point * 2 <= 100000 && visited[temp.point * 2] == 0)
		{ 
			public_queue.push(point_dept(temp.point * 2, temp.dept + 1));
			visited[temp.point *2] = 1;
		}
	}

	return -1;
}

int main()
{
	int subin;

	cin >> subin;
	cin >> brother;

	/*for (int i = 0; i <= 100000; i++)
	{
		if (subin!=i)
			arr[i] = INT_MAX;
	}*/

	res = bfs(subin, brother);

	cout << res << endl;

	return 0;
}